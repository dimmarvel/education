#ifndef _HELPERS_H
#define _HELPERS_H
#include <time.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE !(FALSE)

#define SWAP(x,y)       \
do {                    \
    typeof(x) _x = x;   \
    typeof(y) _y = y;   \
    x = _y;             \
    y = _x;             \
} while(0)

static int get_rand(const int from, const int to) 
{
    return from + rand() % (to - from); 
}

#endif /* _HELPERS_H */
