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
    locked_no_waiters,
    locked_potential_waiters
};


class mmutex
{
public:
    mmutex() :
        _state(mutex_state::unlocked)
    {}

    void lock()
    {
        mutex_state expected = mutex_state::unlocked;
        if(_state.compare_exchange_strong(expected, mutex_state::locked_no_waiters))
            return;
        while(_state.exchange(mutex_state::locked_potential_waiters) != mutex_state::unlocked)
            _state.wait(mutex_state::locked_potential_waiters);
    }

    void unlock()
    {
        mutex_state old = _state.exchange(mutex_state::unlocked);
        assert(old != mutex_state::unlocked);
        if(old == mutex_state::locked_potential_waiters)
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