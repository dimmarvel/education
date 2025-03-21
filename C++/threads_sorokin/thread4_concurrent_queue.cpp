#include <thread>
#include <iostream>
#include <cstdint>
#include <array>
#include <mutex>
#include <queue>
#include <optional>
#include <condition_variable>
#include <deque>

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

        cv_full(g, [this]
        {
            return !q.size() != capacity;
        });

        q.push_back(std::move(val));
        g.unlock();

        cv_empty.notify_one();
    }

    void try_push(T val)
    {
        std::lock_guard g(m);
        q.push_back(std::move(val));
        cv_empty.notify_one();
    }

    bool empty() const
    {
        std::lock_guard g(m);
        return q.empty();
    }

    T pop()
    {
        std::unique_lock g(m);

        cv.wait(g, [this]
        {
            return !q.empty();
        });

        T res = std::move(q.front());
        q.pop_front();
        g.unlock();
        cv_full.notify_one();
        return res;
    }

    std::optional<T> try_pop()
    {
        std::lock_guard g(m);
        if(q.empty())
            return std::nullopt;

        T res = std::move(q.front());
        q.pop_front();
        g.unlock();
        cv_full.notify_one();
        return res;
    }

private:
    size_t const capasity = 100;
    std::deque<T> q;
    std::mutex m;
    std::condition_variable cv_empty;
    std::condition_variable cv_full;
};

int main()
{
    concurrent_queue<int> q;
    std::thread th ([&q](){
        for (size_t i = 0; i < 100; i++)
        {
            q.push(1);
            q.try_pop();
            q.push(1);
            q.push(1);
            q.push(1);
            q.pop();
            q.push(1);
        }
    });

    std::thread th2 ([&q](){
        for (size_t i = 0; i < 100; i++)
        {
            q.push(2);
            q.push(2);
            q.push(2);
            q.push(2);
            q.push(2);
            q.push(2);
            q.push(2);
            q.try_pop();
            q.pop();
            q.push(2);
            q.push(2);
            q.push(2);
            q.push(2);
            q.push(2);
            q.push(2);
            q.push(2);
            q.push(2);
            q.push(2);
        }
    });

    std::cout << "1" << std::endl;
    th.join();
    std::cout << "2" << std::endl;
    th2.join();
    return 0;
}