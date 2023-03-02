#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct doc
{
    string name;
    void open() { cout << "doc with name: " << name << " was opened\n"; }
    void paste() { cout << "paste doc\n"; }
};

class app
{
public:
    app() = default;
    void add_doc(const doc& d) { _docs.push_back(d); }

private:
    vector<doc> _docs;
};

class command
{
public:
    virtual ~command() = default;
    virtual void execute() = 0;
protected:
    command() = default;
};

class open_command : public command
{
public:
    open_command(shared_ptr<app> a)
    :
    _app(a)
    {}

    virtual void execute() override
    {
        string name = ask_user();
        if(!name.empty())
        {
            doc d{name};
            _app->add_doc(d);
            d.open();
        }
    }

protected:
    virtual string ask_user() { return "nice doc"; }

private:
    shared_ptr<app> _app;
    string _response;
};

class paste_command : public command
{
public:
    paste_command(const doc& d)
    :
    _doc(d)
    {}

    virtual void execute() override 
    {
        _doc.paste();
    }

private:
    doc _doc;
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