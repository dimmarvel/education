
/*
Client Producer - subscribes to a topic, and then sends a message using the SendJson method, 
which contains some data and time in json format

Consumer client - subscribes to the topic and listens to it, 
accepting data from the producer in json format
*/
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>
#include <queue>
#include <cppkafka/cppkafka.h>
#include <nlohmann/json.hpp>

using namespace std;
using namespace cppkafka;
using json = nlohmann::json;


void sleep()
{
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(2000ms);
}

struct ClientConsumer
{
	void ShowMessages()
	{
		cout << "All recieved messages: " << endl;
		while(!_q_messages.empty())
		{
			string value = _q_messages.front();
			_q_messages.pop();
			cout << value << endl;
		}
	}

	void ListenTopics()
	{
		_consumer.subscribe(_topics);

		int i = 0;

		//listen only 6 times
		while (i++ < 6)
		{
			Message msg = _consumer.poll();
			if (!msg) continue;

			cout <<"Received message, info: \n"
				 << "Topic: "	<< msg.get_topic() << "/" << msg.get_partition() << endl
				 << "Offset: " << msg.get_offset() << endl
				 << "Payload: " << msg.get_payload() << endl;

			_q_messages.push(msg.get_payload());

			_consumer.commit(msg);
			sleep();
		}
	}

public:
	ClientConsumer(Configuration& config, const vector<string>& topics)
	: _consumer(config),
	  _topics(topics)
	{
		cout << "Wait message from topics: " << endl;
		for(const auto& it : _topics)
			cout << it << " " << endl;
	}

private:
	vector<string> 	_topics;
	queue<string> 	_q_messages;
	Consumer 		_consumer;
};

struct ClientProducer
{
	void SendJson(json j)
	{
		sleep();

		j["time"] = get_time();
		string message = j.dump();

		for(auto& it : _topics)
			_producer.produce(MessageBuilder(it).partition(0).payload(message));
	}

	void SendTimeToTopics()
	{
		int i = 0;
		while(true)
		{
			string time = to_string(i++) + ") " + get_time();

			for(auto& it : _topics)
				_producer.produce(MessageBuilder(it).partition(0).payload(time));

			sleep();
		}
	   _producer.flush();
	}

public:
	ClientProducer(Configuration& config, const vector<string>& topics)
	: _producer(config),
	  _topics(topics) {}

private:
	string get_time()
	{
		time_t result = time(nullptr);
		string time = asctime(localtime(&result));

		string::iterator it = remove(time.begin(), time.end(), '\n');
		time.erase(it, time.end());

		return time;
	}

private:
	vector<string> 	_topics;
	Producer 		_producer;
};

int main()
{
	json j;
	j["time"] = "Empty";
	j["data"] = 1111;

	Configuration config =
	{
			{"metadata.broker.list", "127.0.0.1:9092"},
			{"group.id","mygroup"}
	};

	ClientConsumer cc(config, { "test-topic", "second-topic" });
	ClientProducer cp(config, { "test-topic", "second-topic" });

	std::thread th1([&cc](){
		cc.ListenTopics();
		cc.ShowMessages();
	});

	std::thread th2([&cp, &j](){

		//send json 5 times
		for(int i = 0; i < 5; i++)
		{
			cp.SendJson(j);
		}

	});

	th1.join();
	th2.join();

}
