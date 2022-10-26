#include <type_traits>
#include <string>
#include <iostream>

template <typename T>
decltype(auto)
sm_move(T&& param)
{
    using ResultType = typename std::remove_reference<T>::type&&;
    return static_cast<ResultType>(param);
}

int main()
{
    std::string s;
    std::string st = "sft";
    std::cout << "before move:" << std::endl;
    std::cout << "s = " << s << std::endl;
    std::cout << "st = " << st << std::endl;
    s = sm_move(st);
    std::cout << "after move:" << std::endl;
    std::cout << "s = " << s << std::endl;
    std::cout << "st = " << st << std::endl;
    return 0;
}