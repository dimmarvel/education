#include <thread>
#include <iostream>
#include <cstdint>
#include <array>
#include <mutex>
#include <atomic>
#include <cassert>

enum class mutex_state
{
    unlocked,
    locked
};


class mmutex
{
public:
    mmutex() :
        _state(mutex_state::unlocked)
    {}

    void lock()
    {
        while(_state.exchange(mutex_state::locked) == mutex_state::locked)
        {
            _state.wait(mutex_state::locked); //C++20 wait until notify or _state changed
        }
    }

    void unlock()
    {
        _state.store(mutex_state::unlocked);
        _state.notify_one();
    }

private:
    std::atomic<mutex_state> _state;
};

int main()
{
    mmutex m;
    m.lock();
    m.unlock();
    return 0;
}