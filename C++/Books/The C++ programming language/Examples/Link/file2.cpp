#include <iostream>
typedef int I;

extern int f();
extern int a;
extern const double b = 9;
//Константа может получить внешнее связывание только с помощью явного описания:

int main()
{
    std::cout << f() << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;
}
