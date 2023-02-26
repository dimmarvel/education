#include <iostream>
#include <memory>
#include <string>

using namespace std;
class composite;

class component
{
public:
    virtual ~component() = default;
    virtual shared_ptr<composite> get_composite() { return nullptr; }
};

class composite :   public component, 
                    public std::enable_shared_from_this<composite>
{
public:
    composite() = default;
    virtual shared_ptr<composite> get_composite() override { return dynamic_pointer_cast<composite>(shared_from_this()); }
    virtual void add(shared_ptr<component> cmpnt);
};

class leaf :    public component, 
                public std::enable_shared_from_this<leaf>
{
public:
    leaf() = default;
    void operation() { cout << "operation left\n"; }
    virtual shared_ptr<composite> get_composite() override { return dynamic_pointer_cast<composite>(shared_from_this()); }
};

int main()
{
    shared_ptr<composite> a_composite = make_shared<composite>();
    shared_ptr<leaf> a_leaf = make_shared<leaf>();
    
    shared_ptr<component> component;
    shared_ptr<composite> composite_test;

    component = a_composite;
    if(composite_test = component->get_composite())
        composite_test->add(make_shared<leaf>()); // add
    
    component = a_leaf;
    if(composite_test = component->get_composite())
        composite_test->add(make_shared<leaf>()); // doesnt add

    return 0;
}