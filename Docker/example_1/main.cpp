#include <iostream>
#include <chrono>
#include <thread>
int main() {
    using namespace std::chrono_literals;
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Sleep 10 sec..." << std::endl;
    std::this_thread::sleep_for(10s);
    std::cout << "End..." << std::endl;
    return 0;
}
