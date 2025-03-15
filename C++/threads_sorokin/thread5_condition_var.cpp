#include <condition_variable>
std::condition_variable cv;
void ad20_waiter()
{
    cv.wait();
}
void ad20_notifyer()
{
    cv.notify_one();
    cv.notify_all();
}

int main()
{
    
    return 0;
}