#include <memory>

struct Impl
{
    std::string name;
    int i;
};

class Widget
{
public:
    Widget();

    Widget(const Widget&& rhs);
    Widget& operator=(const Widget&& rhs);

    ~Widget();

public:
    std::unique_ptr<Impl> pImpl;
};
