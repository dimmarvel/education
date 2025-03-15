#include <thread>
#include <iostream>
#include <cstdint>
#include <array>
#include <mutex>

struct account
{
    size_t balance;
    std::mutex m;
};

std::array<account, 1000> accounts;

void transfer(size_t from, size_t to, int32_t amount)
{
    std::lock_guard g(accounts[from].m);
    std::lock_guard g(accounts[to].m);
    if(accounts[from].balance < amount)
        throw std::runtime_error("insufficient funds");
    accounts[from].balance -= amount;
    accounts[to].balance += amount;
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