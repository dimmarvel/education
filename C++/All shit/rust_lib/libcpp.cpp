#include<iostream>

extern "C" 
{
    uint64_t add_cpp_func(uint32_t a, uint32_t b);
}

uint64_t add_cpp_func(uint32_t a, uint32_t b)
{
    std::cout << "a + b = " << a + b << '\n'; 
    return a + b;
}