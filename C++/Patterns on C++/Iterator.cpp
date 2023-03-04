#include <iostream>
#include <memory>
#include <stdio.h>
#include <string>
#include <vector>
#include <exception>

using namespace std;

#define CAPACITY_DEFAULT 10

template<class item>
class list
{
public:
    list(int size = CAPACITY_DEFAULT) {}
    int count() const { return _count; }
    item& get(int index) { return _items[index]; }
    void push(const item& it) { _items.push_back(it); _count++; }

private:
    int _count;
    std::vector<item> _items;
};

template<class item>
class iter
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool is_done() = 0;
    virtual item current_item() = 0;

protected:
    iter() {}
};

template<class item>
class list_iterator : public iter<item>
{
public:
    
    list_iterator(shared_ptr<list<item>> lst)
    :
    _list(lst),
    _current(0)
    {}

    virtual void first() override
    {
        _current = 0;
    }

    virtual void next() override
    {
        _current++;
    }

    virtual bool is_done() override
    {
        return _current >= _list->count();
    }

    virtual item current_item() override
    {
        if(is_done())
            cout << "ERROR out of range" << endl;
        return _list->get(_current);
    }

private:
    shared_ptr<list<item>> _list;
    int _current;
};

struct employer
{
    string name = "default name";
};

int main()
{ 
    shared_ptr<list<employer>> empls = make_shared<list<employer>>();

    empls->push(employer{"empl1"});
    empls->push(employer{"empl2"});
    empls->push(employer{"empl3"});
    empls->push(employer{"empl4"});
    empls->push(employer{"empl5"});

    list_iterator<employer> empl_it(empls);
    for(empl_it.first(); !empl_it.is_done(); empl_it.next())
    {
        cout << empl_it.current_item().name << endl;
    }

    return 0;
}
