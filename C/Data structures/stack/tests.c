#include "tests.h"
#include "stack.h"
#include "../helpers.h"
#include <stdio.h>

void test_stack()
{
    printf("\n-------test_stack-------\n");

    printf("test 1: push pop - ");
    stack* stk = create_stack();
    fill_stack(stk, 0, 100);
    int boolean = TRUE;
    for(int i = (stk->top - 1); (i <= 0) && (boolean == TRUE); --i)
        if(pop(stk) != i)
            boolean = FALSE;
    CHECK_EXPR(boolean, "invalid pop push stack");
    
    delete_stack(stk);
    printf("--------------------------\n");
}

void do_tests()
{
    test_stack();
}
