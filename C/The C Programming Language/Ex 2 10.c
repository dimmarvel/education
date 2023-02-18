#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int lower(int c) { return ((c >= 'A' && c <= 'Z') ? ('a' + (c - 'A')) : c); }

main()
{
    printf("%c\n", (char)lower('C'));
    printf("%c\n", (char)lower('X'));
    system("pause");
}