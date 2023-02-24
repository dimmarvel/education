#include <memory>
#include <iostream>
#include <string>

using namespace std;

class window_impl
{
public:
    virtual ~window_impl() {}
    virtual void draw_contents() = 0;
    virtual void open() = 0;
    virtual void close() = 0;

protected:
    window_impl() = default;
};
class window
{
public:
    window(shared_ptr<window_impl> impl) 
    : 
    _impl(static_pointer_cast<window_impl>(impl)) 
    {}
    virtual ~window() {}
    
    virtual void draw_contents() { std::cout << "window draw_contents()\n"; _impl->draw_contents(); };
    virtual void open() { std::cout << "window draw_contents()\n"; _impl->open(); }
    virtual void close() { std::cout << "window draw_contents()\n"; _impl->close(); }


protected:
    shared_ptr<window_impl> get_impl() { return _impl; }

private:
    shared_ptr<window_impl> _impl;
};

class xos_window_impl : public window_impl
{
public:
    xos_window_impl() = default;
    
    virtual void draw_contents() override { std::cout << "xos_window_impl draw_contents()\n"; }
    virtual void open() override { std::cout << "xos_window_impl open()\n"; }
    virtual void close() override { std::cout << "xos_window_impl close()\n"; }
};

class yos_window_impl : public window_impl
{
public:
    yos_window_impl() = default;
    
    virtual void draw_contents() override { std::cout << "yos_window_impl draw_contents()\n"; }
    virtual void open() override { std::cout << "yos_window_impl open()\n"; }
    virtual void close() override { std::cout << "yos_window_impl close()\n"; }

};

int main()
{
    shared_ptr<window_impl> xos_impl = make_shared<xos_window_impl>();
    shared_ptr<window_impl> yos_impl = make_shared<yos_window_impl>();
    shared_ptr<window> wndw = make_shared<window>(xos_impl);

    wndw->open();
    wndw->close();
    wndw->draw_contents();

    wndw = make_shared<window>(yos_impl);

    wndw->open();
    wndw->close();
    wndw->draw_contents();

    return 0;
}