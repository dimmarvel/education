#include <type_traits>
#include <string>
#include <iostream>
#include <vector>
template <typename T>
decltype(auto)
sm_move(T&& param)
{
    using ResultType = typename std::remove_reference<T>::type&&;
    return static_cast<ResultType>(param);
}

void f(std::vector<int>& v)
{
    std::vector<int> v2{1,2,3};
    v = v2;
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

    std::vector<int> v{1,2,3,4};
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    
    f(v);
    std::cout << "after" << std::endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }

    return 0;
}