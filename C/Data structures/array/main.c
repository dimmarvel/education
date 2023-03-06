#include "array.h"
#include "tests.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, int** argv)
{
    srand(time(0));
    do_tests();
    return 0;
}
