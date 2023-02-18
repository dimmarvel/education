#include "widget.hpp"
#include "gadget.hpp"
#include <string>
#include <vector>

struct Widget::Impl
{
    std::string name;
    std::vector<double> data;
    gadget a, b, c, v;
};

Widget::Widget() : pImpl(std::make_unique<Impl>()) {}
