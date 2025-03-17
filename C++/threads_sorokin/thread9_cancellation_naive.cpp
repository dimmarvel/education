#include <thread>
#include <iostream>
#include <atomic>

void thread_proc(std::atomic<bool> const* should_quit)
{
    for(;;)
    {
        if(should_quit)
            break;
    }
}

void thread_run()
{
    std::atomic<bool> should_quit = false;
    std::thread th ([&should_quit](){
        thread_proc(&should_quit);
    });
    should_quit = true;
}

//наивная реализация 