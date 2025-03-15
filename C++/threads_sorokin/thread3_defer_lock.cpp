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
    std::unique_lock g_from(accounts[from].m, std::defer_lock); //unique_lock - std::defer_lock - залочь потом
    std::unique_lock g_to(accounts[to].m, std::defer_lock);

    std::lock(g_from, g_to); // лок двух сразу, чтобы небыло гонки при таком вызове transfer(1, 2, 0) transfer(2, 1, 0)

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