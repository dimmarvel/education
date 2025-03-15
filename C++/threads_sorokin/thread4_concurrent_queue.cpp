#include <thread>
#include <iostream>
#include <cstdint>
#include <array>
#include <mutex>
#include <queue>
#include <optional>

template <typename T>
class concurrent_queue
{
public:
    concurrent_queue() = default;
    concurrent_queue(const concurrent_queue& other) = delete;
    concurrent_queue& operator=(const concurrent_queue& other) = delete;

    void push(T val)
    {
        std::lock_guard g(m);
        q.push_back(std::move(val));
    }

    bool empty() const
    {
        std::lock_guard g(m);
        return q.empty();
    }

    T pop()
    {
        std::lock_guard g(m);
        T res = std::move(q.front());
        q.pop_front();
        return res;
    }

    std::optional<T> try_pop()
    {
        std::lock_guard g(m);
        if(q.empty())
            return std::nullopt;

        T res = std::move(q.front());
        q.pop_front();
        return res;
    }

private:
    std::queue<T> q;
    std::mutex m;
};

int main()
{
    concurrent_queue<int> q;
    std::thread th ([&q](){
        for (size_t i = 0; i < 100; i++)
        {
            q.push(1);
        }
    });

    std::thread th2 ([&q](){
        for (size_t i = 0; i < 100; i++)
        {
            q.push(2);
        }
    });

    std::cout << "1" << std::endl;
    th.join();
    std::cout << "2" << std::endl;
    th2.join();
    return 0;
}