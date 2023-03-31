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
    fill_list(lst, 0, 3);
    clear_list(lst);
    CHECK_EXPR(!lst->size && !lst->head, "invalid clear");
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

void test_compare_list()
{
    printf("\n-------test_compare_list-------\n");

    linked_list* lst = create_list();
    linked_list* lst2 = create_list();
    linked_list* lst3 = create_list();
    linked_list* lst4 = create_list();

    fill_list(lst, 0, 10);
    fill_list(lst2, 0, 10);
    fill_list(lst3, -5, 5);
    fill_list(lst4, 0, 11);

    printf("test 1: compare same - ");
    CHECK_EXPR(compare_list(lst, lst2), "invalid compare same");
    printf("test 2: compare diff size - ");
    CHECK_EXPR(!compare_list(lst, lst3), "invalid compare diff size");
    printf("test 3: compare diff elem - ");
    CHECK_EXPR(!compare_list(lst, lst4), "invalid compare diff elem");

    delete_list(lst);
    delete_list(lst2);
    delete_list(lst3);
    delete_list(lst4);
    
    printf("--------------------------\n");
}

void test_shuffle_list()
{
    printf("\n-------test_shuffle_list-------\n");
    printf("test 1: shuffle - ");

    linked_list* lst = create_list();
    linked_list* lst2 = create_list();
    fill_list(lst, 0, 10);
    fill_list(lst2, 0, 10);
    shuffle_list(lst);
    CHECK_EXPR(!compare_list(lst, lst2), "invalid shuffle");
    delete_list(lst);
    delete_list(lst2);
    
    printf("--------------------------\n");
}

void test_swap_list()
{
    printf("\n-------test_swap_list-------\n");
    printf("test 1: swap - ");

    linked_list* lst = create_list();
    fill_list(lst, 0, 3);
    swap_data_list(lst->head, lst->head->next);
    CHECK_EXPR(lst->head->data == 1, "inwalid swap");
    delete_list(lst);
    
    printf("--------------------------\n");
}

void test_reverse_list()
{
    printf("\n-------test_reverse_list-------\n");
    printf("test 1: reverse - ");

    linked_list* lst = create_list();
    linked_list* lst2 = create_list();
    for(int i = 4; i >= 0; --i)
        push_list(lst2, i);
    fill_list(lst, 0, 5);
    reverse_list(lst);
    CHECK_EXPR(compare_list(lst, lst2), "invalid reverse");

    delete_list(lst);
    delete_list(lst2);
    
    printf("--------------------------\n");
}

void do_tests()
{
    test_base_list();
    test_remove_list();
    test_clear_list();
    test_split_list();
    test_compare_list();
    test_shuffle_list();
    test_swap_list();
    test_reverse_list();
}
