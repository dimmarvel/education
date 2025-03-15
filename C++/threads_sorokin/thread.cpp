#include <thread>
#include <iostream>

int main()
{
    std::thread th([](){
        for(size_t i = 0; i < 20; ++i)
        {
            std::cout << std::this_thread::get_id() << std::endl;
        }
    });

    for(size_t i = 0; i < 20; ++i)
    {
        std::cout << std::this_thread::get_id() << std::endl;
    }
    th.join();
    return 0;
}