#include <thread>
#include <iostream>
#include <cstdint>
#include <array>
#include <mutex>
#include <atomic>


std::array<std::atomic<int32_t>, 1000> accounts;

void transfer(size_t from, size_t to, int32_t amount)
{
    int32_t old = accounts[from].load();
    for(;;)
    {
        if(old < amount)
            throw std::runtime_error("insufficient funds");
        if(accounts[from].compare_exchange_weak(old, old - amount))
            break;
    }
    accounts[to] += amount;
}

int main()
{
    std::thread th ([](){
        for (size_t i = 0; i < 100; i++)
        {
            transfer(0, 1, 10);
        }
    });

    std::thread th2 ([](){
        for (size_t i = 0; i < 100; i++)
        {
            transfer(1, 0, 10);
        }
    });

    std::thread th3 ([](){
        for (size_t i = 0; i < 100; i++)
        {
            transfer(0, 1, 10);
        }
    });

    std::cout << "1" << std::endl;
    th.join();
    std::cout << "2" << std::endl;
    th2.join();
    std::cout << "3" << std::endl;
    th3.join();
    return 0;
}