#include <memory>
#include <algorithm>

template <class T>
class custom_shared_ptr
{
public:
    custom_shared_ptr() = default;
    custom_shared_ptr(T* ptr) : _otr(_ptr) { ++_count; }
    custom_shared_ptr(const custom_shared_ptr& custom_ptr) : _ptr(custom_ptr._ptr) { if(custom_ptr._ptr) _count++; else _count--; }
    custom_shared_ptr(const custom_shared_ptr&& custom_ptr) : _ptr(std::move(custom_ptr._ptr)) {}

    custom_shared_ptr& operator=(const custom_shared_ptr& other)
    {
        this->_count--;
        return *this;
    }

    ~custom_shared_ptr()
    {
        if(_count)
        if(--_count == 0)
            delete _ptr;
    }

private:
    static size_t _count = 0;
    T* _ptr = nullptr;
};