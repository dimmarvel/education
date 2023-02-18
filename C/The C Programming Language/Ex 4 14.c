#include <math.h>
#include <stdio.h>
#include <string.h>

#define LEN 100
#define swap(x, r) x ^= r ^= x ^= r
#define concat(x, r) x##y
#define dprint(expr) printf(#expr " = %g\n", expr)

/*
10 - 2
11 - 3
x = 3 = 11
r = 2 = 10
xor x ^= r = 10 xor 11 = 10 = 2
xor r ^= x = 01 xor 10 = 11 = 3
xor x ^= r = 11 xor 10 = 10 = 2
*/

int main()
{

    int n = 3;
    int w = 2;

    swap(n, w);

    printf("n = %d\n", n);
    printf("w = %d\n", w);

    dprint(n / w);

    system("pause");
    return 0;
}
