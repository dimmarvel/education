#include "tests.h"
#include "binary_tree.h"
#include "../helpers.h"
#include <stdio.h>

void test_binary_tree()
{
    printf("\n-------test_binary_tree-------\n");
    printf("test 1: create binary_tree - ");
    binary_tree* bst = create_bst();
    fill_bst(bst);
    print_bst(bst->root);

    printf("--------------------------\n");
}

void do_tests()
{
    test_binary_tree();
}
