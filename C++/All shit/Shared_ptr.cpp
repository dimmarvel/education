#include <iomanip>
#include <iostream>

using namespace std;

template<typename T>
class shard_ptr
{
public:
    shard_ptr() {}

    shard_ptr(T* ptr) 
    :
    ptr(ptr),
    counter(new int(1))
    {}

    shard_ptr(const shard_ptr& other)
    :
    ptr(other.ptr),
    counter(other.counter)
    {
        ++*counter;
    }

    shard_ptr(shard_ptr&& other)
    :
    ptr(other.ptr),
    counter(other.counter)


private:
    int* counter = nullptr;
    T* ptr = nullptr;
};

int main()
{
    system("pause");
}