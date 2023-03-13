#include "tests.h"
#include "linked_list.h"
#include "../helpers.h"
#include <stdio.h>

void test_base_list()
{
    printf("\n-------test_linked_list-------\n");

    printf("test 1: create list - ");
    linked_list* lst = create_list();
    fill_list(lst, 0, 10);
    int i = 0;
    int boolean = TRUE;
    for(node_t* curr = get_first(lst); get_current(lst) && boolean == TRUE; curr = get_next(lst))
        if(curr->data != i++)
            boolean = FALSE;
    CHECK_EXPR(boolean, "invalid create/push/iterator list");

    delete_list(lst);
    printf("--------------------------\n");
}

void test_remove_list()
{
    printf("\n-------test_remove_list-------\n");

    printf("test 1: remove - ");
    linked_list* lst = create_list();
    fill_list(lst, 0, 10);
    for(int i = 9; i > 5; --i)
        remove_list(lst, i);

    CHECK_EXPR(!find_list(lst, 7), "invalid remove");
    delete_list(lst);
    printf("--------------------------\n");
}

void do_tests()
{
    test_base_list();
    test_remove_list();
}
