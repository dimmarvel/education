#include <fstream>
#include <iostream>
using namespace std;

template <typename T>
struct An
{
    An() { clear(); }

    T* operator->() { return get0(); }
    const T* operator->() const { return get0(); }
    void operator=(T* t) { data = t; }

    bool isEmpty() const { return data == 0; }
    void clear() { data = 0; }
    void init()
    {
        if (isEmpty())
            reinit();
    }
    void reinit() { anFill(*this); }

private:
    T* get0() const
    {
        const_cast<An*>(this)->init();
        return data;
    }

    T* data;
};

template <typename T>
void anFill(An<T>& a)
{
    throw std::runtime_error(std::string("Cannot find implementation for interface: ") + typeid(T).name());
}

template <>
void anFill<X>(An<X>& a)
{
    static X x;
    a = &x;
}

struct X
{
    X() : counter(0) {}
    void action() { std::cout << ++counter << ": in action" << std::endl; }

    int counter;
};

int main()
{
    setlocale(LC_ALL, "Rus");

    system("pause");
    return 0;
}
