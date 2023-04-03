#include "tests.h"
#include "binary_tree.h"
#include "../helpers.h"
#include <stdio.h>

#define ARR_SIZE 12
const int TEST_ARR[ARR_SIZE] = {5, 0, 7, 4, 6, 9, 8, 1, 3, 8, 2, 10};

void fill_test(binary_tree* bst)
{
    for(int i = 0; i < ARR_SIZE; ++i)
        add_bst(bst, TEST_ARR[i]);
}

void test_bst()
{
    printf("\n-------test_binary_tree-------\n");
    printf("test 1: create binary_tree - ");
    binary_tree* bst = create_bst();
    fill_test(bst);
    CHECK_EXPR(bst, "bad binary tree create");
    delete_bst(bst);
}
    
void test_find_bst()
{
    printf("\n-------test_find_binary_tree-------\n");
    printf("test 1: default find - ");
    binary_tree* bst = create_bst();
    fill_test(bst);
    
    BOOL all_find = TRUE;

    for(int i = 0; i < ARR_SIZE && all_find; ++i)
        if(!find_bst(bst, TEST_ARR[i])) 
            all_find = FALSE;

    CHECK_EXPR(all_find, "bad find binary tree");

    printf("test 2: find bst max - ");
    CHECK_EXPR(find_bst_max(bst)->data == 10, "bad find max != 10");

    printf("test 3: find bst min - ");
    CHECK_EXPR(find_bst_min(bst)->data == 0, "bad find min != 0");
    
    //TODO: add default root find min max

    delete_bst(bst);
    printf("--------------------------\n");
}

void test_bfs_bst()
{
    printf("\n-------test_bfs_tree-------\n");
    printf("test 1: default find - ");
    binary_tree* bst = create_bst();
    fill_test(bst);

    printf("\n %d \n, ", get_height(bst->root));

    bfs(bst->root);

    delete_bst(bst);
    printf("--------------------------\n");
}

void do_tests()
{
    test_bst();
    test_find_bst();
    test_bfs_bst();
}
