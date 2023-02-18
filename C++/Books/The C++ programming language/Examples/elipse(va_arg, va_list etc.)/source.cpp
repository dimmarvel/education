#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

extern void error(int...);
extern char* itoa(int);

int main(int argc, char* argv[])
{
    switch (argc)
    {
    case 1:
        error(0, argv[0], (char*)0);
        break;
    case 2:
        error(0, argv[0], argv[2], (char*)0);
        break;
    default:
        error(1, argv[0], "With", itoa(argc - 1), "argumets", (char*)0);
    }
    return 0;
}
