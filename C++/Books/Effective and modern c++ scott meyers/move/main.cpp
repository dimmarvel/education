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

int main()
{
    std::string s;
    std::string st = "sft";
    s = sm_move(st);
    return 0;
}
