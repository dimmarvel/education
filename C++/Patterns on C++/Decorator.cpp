#include <iostream>
#include <memory>
#include <stdio.h>
#include <string>

using namespace std;
class component
{
public:
    virtual ~component() = default;
    virtual string operation() = 0;
};

class some_component : public component
{
public:
    some_component() = default;
    virtual string operation() override { return "some component"; }
};

class decorator : public component
{
public:
    decorator(shared_ptr<component> comp) 
    :
    _comp(dynamic_pointer_cast<component>(comp))
    {}

    virtual ~decorator() = default;
    
    virtual string operation() override { return this->_comp->operation(); }

private:
    shared_ptr<component> _comp;
};

class concrete_decorA : public decorator
{
public:
    concrete_decorA(shared_ptr<component> comp) 
    :
    decorator(comp)
    {}

    string operation() override { return "Concrete decorA(" + decorator::operation() + ")"; }
};

class concrete_decorB : public decorator
{
public:
    concrete_decorB(shared_ptr<component> comp) 
    :
    decorator(comp)
    {}

    string operation() override { return "Concrete decorB(" + decorator::operation() + ")"; }
};

int main()
{ 
    shared_ptr<component> comp = make_shared<some_component>();
    cout << comp->operation() << endl;
    shared_ptr<component> decor1 = make_shared<concrete_decorA>(comp);
    shared_ptr<component> decor2 = make_shared<concrete_decorB>(decor1);
    cout << decor1->operation() << endl;
    cout << decor2->operation() << endl;

    return 0;
}