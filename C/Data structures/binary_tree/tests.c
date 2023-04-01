#include "tests.h"
#include "binary_tree.h"
#include "../helpers.h"
#include <stdio.h>

void test_bst()
{
    printf("\n-------test_binary_tree-------\n");
    printf("test 1: create binary_tree - ");
    binary_tree* bst = create_bst();
    fill_bst(bst);
    print_bst(bst->root);
    delete_bst(bst);
} 
    
void test_find_bst()
{
    printf("\n-------test_find_binary_tree-------\n");
    printf("test 1: create binary_tree - ");
    binary_tree* bst = create_bst();
    fill_bst(bst);
    if(find_bst(bst, 11)) printf("FOUND\n");
    if(!find_bst(bst, 2222)) printf("NOTFOUND\n");
    if(find_bst(bst, 13)) printf("FOUND\n");
    if(find_bst(bst, 14)) printf("FOUND\n");
    if(find_bst(bst, 0)) printf("FOUND\n");
    if(!find_bst(bst, 15)) printf("NOTFOUND\n");
    print_bst(bst->root);
    delete_bst(bst);
    printf("--------------------------\n");
}

void do_tests()
{
    test_bst();
    test_find_bst();
}
