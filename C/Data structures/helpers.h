#ifndef _HELPERS_H
#define _HELPERS_H
#include <time.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE !(FALSE)
#define BOOL int

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

#define CHECK(expr1, expr2)                       \
if((expr1) == (expr2)) printf("passed\n");        \
else printf("ERROR: %s == %s \n", #expr1, #expr2) \

#define CHECK_EXPR(expr1, bad_info)                     \
if(expr1) printf("passed\n");                           \
else printf("ERROR: %s, info: %s\n", #expr1, bad_info)  \

#define ERROR(info) { printf("ERROR: %s\n", info); exit(1); }

#endif /* _HELPERS_H */
