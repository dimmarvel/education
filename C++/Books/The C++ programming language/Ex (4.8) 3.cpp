#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        printf("Hello, %s\n", argv[i]);
    }
    return 1;
}
