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

void test_clear_list()
{
    printf("\n-------test_clear_list-------\n");

    printf("test 1: clear - ");
    linked_list* lst = create_list();
    fill_list(lst, 0, 10);
    clear_list(lst);
    CHECK_EXPR(!lst->head, "invalid clear");
    delete_list(lst);
    printf("--------------------------\n");
}

void test_split_list()
{
    printf("\n-------test_split_list-------\n");

    printf("test 1: split - ");
    linked_list* lst = create_list();
    int before_size = lst->size / 2;
    fill_list(lst, 0, 10);
    linked_list* half = split_half_list(lst);
    CHECK_EXPR(!(lst->size == before_size), "invalid split");
    delete_list(lst);
    delete_list(half);
    printf("--------------------------\n");
}

void do_tests()
{
    test_base_list();
    test_remove_list();
    test_clear_list();
    test_split_list();
}
