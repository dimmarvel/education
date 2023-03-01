#include <iostream>
#include <memory>
#include <stdio.h>
#include <string>

using namespace std;

using topic = int;
const topic NO_HELP_TOPIC = -1;
const topic PRINT_TOPIC = 1;
const topic PAPER_ORIENTATION_TOPIC = 2;
const topic APPLICATION_TOPIC = 3;

class help_handler
{
public:
    help_handler(shared_ptr<help_handler> s = nullptr, topic t = NO_HELP_TOPIC)
    :
    _successor(s),
    _topics(t)
    {}
    
    virtual void handle_help() { if(_successor) _successor->handle_help(); }
    virtual bool has_help() { return _topics != NO_HELP_TOPIC; }
    virtual void set_handler(shared_ptr<help_handler> hh, topic t) { _successor = hh; _topics = t;}

private:
    shared_ptr<help_handler> _successor;
    topic _topics;
};

class widget : public help_handler
{
protected:
    widget(shared_ptr<widget> parent, topic t = NO_HELP_TOPIC)
    :
    help_handler(dynamic_pointer_cast<help_handler>(parent), t),
    _parent(parent)
    {}
    
private:
    shared_ptr<widget> _parent;
};

class button : public widget {
public:
    button(shared_ptr<widget> parent, topic t = NO_HELP_TOPIC)
    :
    widget(parent, t)
    {}

    virtual void handle_help()
    {
        if (has_help()) {
            cout << "info about batton" << endl;
        } 
        else 
        {
            help_handler::handle_help();
        }
    }
};

class dialog : public widget {
public:
    dialog(shared_ptr<help_handler> h, topic t = NO_HELP_TOPIC) 
    : 
    widget(nullptr) 
    {
        set_handler(h, t);
    }

    virtual void handle_help() 
    {
        if (has_help()) {
            cout << "info about dialog" << endl;
        } 
        else 
        {
            help_handler::handle_help();
        }
    }
};

class app : public help_handler {
public:
    app(topic t = NO_HELP_TOPIC) 
    : 
    help_handler(nullptr, t) 
    {}

    virtual void handle_help() 
    {
        cout <<
        "dialog\n" <<
        "button\n" << 
        "widget\n";
    }
};

int main()
{ 
    shared_ptr<app> application = make_shared<app>(APPLICATION_TOPIC);
    shared_ptr<dialog> dlg = make_shared<dialog>(application, PRINT_TOPIC);
    shared_ptr<button> btn = make_shared<button>(dlg, PAPER_ORIENTATION_TOPIC);
    btn->handle_help();
    dlg->handle_help();
    application->handle_help();
    return 0;
}