#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>

std::condition_variable foo;
std::mutex mtx;

void secondThread()
{
	while (true)
	{
		foo.wait(std::unique_lock<std::mutex>(mtx));
		std::cout << " ----------------------------" << std::endl;
		std::cout << "|processing a notification...|" << std::endl;
		std::cout << " ----------------------------" << std::endl;
	}
}
int main()
{
	std::thread subThread = std::thread(&secondThread);
	int count = 0;
	while (true)
	{
		if (count % 10 == 0)
		{
			foo.notify_one();
		}
		std::cout << "Main thread working on gathering notifications..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		count++;
	}
	return 0;
}