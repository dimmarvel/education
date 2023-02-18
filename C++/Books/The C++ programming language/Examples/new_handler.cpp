#include <iostream>
#include <new>
#include <stdlib.h>

void out_of_store()
{
    std::cerr << "operator new failed: out of store\n";
    exit(1);
}

int main()
{
    std::set_new_handler(&out_of_store);
    char* p = new char[4000000000];
    std::cout << "done, p = " << long(p) << std::endl;
}
