#include <iostream>
#include <list>
#include <string>
using namespace std;

class IObserver
{
public:
    virtual ~IObserver() {};
    virtual void update(const string& message) = 0;
};

class ISubscriber
{
public:
    virtual ~ISubscriber() {};
    virtual void notify() = 0;
    virtual void attach(IObserver* obs) = 0;
    virtual void detach(IObserver* obs) = 0;
};

class Subject : public ISubscriber
{
private:
    list<IObserver*> l_obs;
    string _message;

public:
    virtual ~Subject() { std::cout << "Goodbye, I was the Subject.\n"; }

public:
    void notify() override
    {
        for (auto it : l_obs)
            it->update(_message);
    }

    void attach(IObserver* obs) override { l_obs.push_back(obs); }

    void detach(IObserver* obs) override { l_obs.remove(obs); }

    void CreateMessage(string message = "Empty")
    {
        this->_message = message;
        notify();
    }

    void HowObserversNow() { std::cout << "Here now " << l_obs.size() << " observers in list\n"; }
};

class Observer : public IObserver
{
private:
    string _msg_sub;
    Subject& _subject;
    static int _s_number;
    int _number;

public:
    Observer(Subject& sub) : _subject(sub)
    {
        this->_subject.attach(this);
        std::cout << "Hi, I'm the Observer \"" << ++Observer::_s_number << "\".\n";
        this->_number = Observer::_s_number;
    }

    virtual ~Observer() { cout << "Bue i was obs." << endl; }

    void PrintInfo() { std::cout << "Observer " << this->_number << ": a new message -> " << this->_msg_sub << "\n"; }

    void update(const string& message)
    {
        _msg_sub = message;
        PrintInfo();
    }

    void RemoveMe()
    {
        _subject.detach(this);
        std::cout << "Observer \"" << _number << "\" removed from the list.\n";
    }
};

int Observer::_s_number = 0;

int main()
{
    Subject* subject = new Subject;
    Observer* observer1 = new Observer(*subject);
    Observer* observer2 = new Observer(*subject);
    Observer* observer3 = new Observer(*subject);
    Observer* observer4;
    Observer* observer5;

    subject->CreateMessage("Hello World! :D");
    observer3->RemoveMe();

    subject->CreateMessage("The weather is hot today! :p");
    observer4 = new Observer(*subject);

    observer2->RemoveMe();
    observer5 = new Observer(*subject);

    subject->CreateMessage("My new car is great! ;)");
    observer5->RemoveMe();

    observer4->RemoveMe();
    observer1->RemoveMe();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;
    return 0;
}
