#include <memory>

class Widget
{
public:
    Widget();
    ~Widget() = default;

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};