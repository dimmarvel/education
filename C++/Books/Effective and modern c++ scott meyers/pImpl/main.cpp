#include "widget.hpp"
#include <iostream>

int main()
{
    Widget w1;
    Widget w3;
    w1.pImpl->name = "lox";
    w1.pImpl->i = 10;
    Widget w2(std::move(w1));
    w3 = std::move(w2);
    std::cout << "w1 = " << w1.pImpl->name << " " << w1.pImpl.get() << std::endl;
    std::cout << "w2(move) = " << w2.pImpl->name << " " << w2.pImpl.get() << std::endl;
    std::cout << "w3 = move w2 = " << w3.pImpl->name << " " << w3.pImpl.get() << std::endl;
    std::cout << "w1 = " << w1.pImpl->name << " " << w1.pImpl.get() << std::endl;
    std::cout << "w2 = " << w2.pImpl->name << " " << w2.pImpl.get() << std::endl;
    return 0;
}