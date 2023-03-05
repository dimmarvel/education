#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

class memento
{
public:
    virtual ~memento() {}
    virtual string get_name() const = 0;
    virtual string date() const = 0;
    virtual string state() const = 0;
};

class concrete_memento : public memento
{
private:
    string _state;
    string _date;

public:
    concrete_memento(string state) 
    : 
    _state(state)
    {
        _state = state;
        time_t now = time(0);
        _date = ctime(&now);
    }

    string state() const override { return _state; }
    string get_name() const override { return _date + " / (" + _state.substr(0, 9) + "...)"; }
    string date() const override { return _date; }
};

class originator
{
private:
    string _state;

    string GenerateRandomString(int length = 10)
    {
        const char alphanum[] = "0123456789"
                                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                "abcdefghijklmnopqrstuvwxyz";
        int stringLength = sizeof(alphanum) - 1;

        string random_string;
        for (int i = 0; i < length; i++)
            random_string += alphanum[rand() % stringLength];
        return random_string;
    }

public:
    originator(string state) : _state(state)
    {
        cout << "originator: My initial state is: " << _state << "\n";
    }

    void do_something()
    {
        cout << "originator: I'm doing something important.\n";
        _state = GenerateRandomString(30);
        cout << "originator: and my state has changed to: " << _state << "\n";
    }

    memento* Save() { return new concrete_memento(_state); }

    void Restore(memento* mement)
    {
        _state = mement->state();
        cout << "originator: My state has changed to: " << _state << "\n";
    }
};

class caretaker
{
private:
    vector<memento*> _mementos;
    originator* _originator;

public:
    caretaker(originator* origin) 
    : 
    _originator(origin) 
    {}

    ~caretaker()
    {
        for (auto m : _mementos)
            delete m;
    }

    void backup()
    {
        cout << "\ncaretaker: Saving originator's state...\n";
        _mementos.push_back(_originator->Save());
    }

    void undo()
    {
        if (!_mementos.size())
        {
            return;
        }
        memento* mement = _mementos.back();
        _mementos.pop_back();
        cout << "caretaker: Restoring state to: " << mement->get_name() << "\n";
        try
        {
            _originator->Restore(mement);
        }
        catch (...)
        {
            undo();
        }
    }

    void show_history() const
    {
        cout << "caretaker: Here's the list of mementos:\n";
        for (memento* memento : _mementos)
        {
            cout << memento->get_name() << "\n";
        }
    }
};

void ClientCode()
{
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    originator* origin = new originator("super-duper-super-puper-super.");
    caretaker* care = new caretaker(origin);
    care->backup();
    origin->do_something();
    care->backup();
    origin->do_something();
    care->backup();
    origin->do_something();
    cout << "\n";
    care->show_history();
    cout << "\nClient: Now, let's rollback!\n\n";
    care->undo();
    cout << "\nClient: Once more!\n\n";
    care->undo();

    delete origin;
    delete care;
    return 0;
}