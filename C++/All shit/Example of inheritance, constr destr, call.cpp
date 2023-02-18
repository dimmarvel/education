#include <iostream>
#include <memory>
#include <string>
using namespace std;

class game_object
{
protected:
    int _pos;
    int _data;
    shared_ptr<int> _pint;

public:
    game_object(int pos)
    {
        _pint = make_shared<int>(pos);
        _pos = *_pint;
        _data = _pos;

        cout << "Constructor game_object()" << endl;
        cout << "_pos - " << _pos << endl;
        cout << "_data - " << _data << endl;
        cout << "_pint - " << _pint << " & *_pint - " << *_pint << endl;
    };
    ~game_object() { cout << "Destructor game_object()" << endl; };

public:
    void run() { cout << "run game_object(" << _pos << ", " << _data << ", " << _pint << ")" << endl; }
};

class logic
{
public:
    logic() { cout << "Constructor logic()" << endl; }
    ~logic() { cout << "Destructor logic()" << endl; };

public:
    void run() { cout << "run() logic" << endl; }
};

class car : public game_object, logic
{
    bool _drive;

public:
    car(int go_data, bool drive = 0) : game_object(228u), _drive(drive)
    {
        cout << "Call run:" << endl;
        game_object::run();
        logic::run();
    }

    ~car() { cout << "Destructor car()" << endl; }
};

int main()
{
    game_object f(1337u);
    cout << "-----------------" << endl;
    car c(777);

    system("pause");
    return 0;
}