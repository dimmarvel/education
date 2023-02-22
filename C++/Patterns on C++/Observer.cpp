#include <iostream>
#include <list>
#include <string>

class ISubscriber
{
public:
    virtual ~ISubscriber() {};
    virtual void Update(const std::string& message_from_publisher) = 0;
};

class IPublisher
{
public:
    virtual ~IPublisher() {};
    virtual void Attach(ISubscriber* subscriber) = 0;
    virtual void Detach(ISubscriber* subscriber) = 0;
    virtual void Notify() = 0;
};

class Publisher : public IPublisher
{
public:
    virtual ~Publisher() { std::cout << "Goodbye, I was the Publisher.\n"; }

    void Attach(ISubscriber* subscriber) override { list_subscriber_.push_back(subscriber); }

    void Detach(ISubscriber* subscriber) override { list_subscriber_.remove(subscriber); }

    void Notify() override
    {
        std::list<ISubscriber*>::iterator iterator = list_subscriber_.begin();
        HowManySubscriber();
        while (iterator != list_subscriber_.end())
        {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }

    void CreateMessage(std::string message = "Empty")
    {
        this->message_ = message;
        Notify();
    }
    void HowManySubscriber() { std::cout << "There are " << list_subscriber_.size() << " subscribers in the list.\n"; }

    void SomeBusinessLogic()
    {
        this->message_ = "change message message";
        Notify();
        std::cout << "I'm about to do some thing important\n";
    }

private:
    std::list<ISubscriber*> list_subscriber_;
    std::string message_;
};

class Subscriber : public ISubscriber
{
public:
    Subscriber(Publisher& publisher) : publisher_(publisher)
    {
        this->publisher_.Attach(this);
        std::cout << "Hi, I'm the Subscriber \"" << ++Subscriber::static_number_ << "\".\n";
        this->number_ = Subscriber::static_number_;
    }
    virtual ~Subscriber() { std::cout << "Goodbye, I was the Subscriber \"" << this->number_ << "\".\n"; }

    void Update(const std::string& message_from_publisher) override
    {
        message_from_publisher_ = message_from_publisher;
        PrintInfo();
    }
    void RemoveMeFromTheList()
    {
        publisher_.Detach(this);
        std::cout << "Subscriber \"" << number_ << "\" removed from the list.\n";
    }
    void PrintInfo()
    {
        std::cout << "Subscriber \"" << this->number_ << "\": a new message is available --> "
                  << this->message_from_publisher_ << "\n";
    }

private:
    std::string message_from_publisher_;
    Publisher& publisher_;
    static int static_number_;
    int number_;
};

int Subscriber::static_number_ = 0;

void ClientCode()
{
    Publisher* publisher = new Publisher;
    Subscriber* subscriber1 = new Subscriber(*publisher);
    Subscriber* subscriber2 = new Subscriber(*publisher);
    Subscriber* subscriber3 = new Subscriber(*publisher);
    Subscriber* subscriber4;
    Subscriber* subscriber5;

    publisher->CreateMessage("Hello World! :D");
    subscriber3->RemoveMeFromTheList();

    publisher->CreateMessage("The weather is hot today! :p");
    subscriber4 = new Subscriber(*publisher);

    publisher->SomeBusinessLogic();

    subscriber2->RemoveMeFromTheList();
    subscriber5 = new Subscriber(*publisher);

    publisher->CreateMessage("My new car is great! ;)");
    subscriber5->RemoveMeFromTheList();

    subscriber4->RemoveMeFromTheList();
    subscriber1->RemoveMeFromTheList();

    delete subscriber5;
    delete subscriber4;
    delete subscriber3;
    delete subscriber2;
    delete subscriber1;
    delete publisher;
}

int main()
{
    ClientCode();
    system("pause");
    return 0;
}