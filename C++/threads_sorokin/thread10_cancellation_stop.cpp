#include <thread>
#include <iostream>
#include <atomic>

void thread_proc(std::stop_token const& stop_tok) // C++20
{
    for(;;)
    {
        if(stop_tok.stop_requested())
            break;
    }
}

void thread_run()
{
    std::stop_source stop_tok;
    std::thread th ([&stop_tok](){
        thread_proc(stop_tok.get_token());
    });
    stop_tok.request_stop();
    th.join();
}
int main(){return 0;}