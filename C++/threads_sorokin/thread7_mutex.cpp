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
    mmutex() :
        _state(mutex_state::unlocked)
    {}

    void lock()
    {
        while(_state.exchange(mutex_state::locked) == mutex_state::locked)
        {}
    }

    void unlock()
    {
        assert(_state == mutex_state::unlocked);
        _state.store(mutex_state::unlocked);
    }

    std::atomic<mutex_state> _state;
};
