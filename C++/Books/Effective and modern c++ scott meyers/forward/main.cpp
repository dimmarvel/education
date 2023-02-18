#include <chrono>
#include <iostream>
#include <vector>

class Widget
{
public:
    int a;
    std::vector<int> b {10};
};

void process(const Widget& lvalArg) // lvalue
{
    std::cout << "lval" << std::endl;
    return;
}

void process(Widget&& rvalArg) // rvalue
{
    std::cout << "rval" << std::endl;
    return;
}

template <typename T>
void logAndProcess(T&& param)
{
    process(std::forward<T>(param));
    process(param);
}

int main()
{
    Widget w;
    std::cout << "call logAndProcess with lval" << std::endl;
    logAndProcess(w);
    std::cout << "call logAndProcess with rval" << std::endl;
    logAndProcess(std::move(w));

    return 0;
}
