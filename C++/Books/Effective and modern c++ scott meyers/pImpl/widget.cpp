#include "widget.hpp"
#include "gadget.hpp"
#include <string>
#include <vector>

Widget::Widget() 
: pImpl(std::make_unique<Impl>())
{}

//move
Widget::Widget(const Widget&& rhs)
: pImpl(nullptr)
{
    if(rhs.pImpl)
        pImpl = std::make_unique<Impl>(*rhs.pImpl);
}

//copy
Widget& Widget::operator=(const Widget&& rhs)
{
    if(!rhs.pImpl)
        pImpl.reset();
    else if (!pImpl)
        pImpl = std::make_unique<Impl>(*rhs.pImpl);
    else
        *pImpl = *rhs.pImpl;

    return *this;
}

Widget::~Widget() = default;
