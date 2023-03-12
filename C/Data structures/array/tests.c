#include "tests.h"
#include "array.h"
#include "../helpers.h"
#include <stdio.h>

void test_removes()
{
    printf("\n-------test_removes-------\n");
    array* arr = create_array();

    printf("test 1: remove_elem - ");
    fill_array(arr, 0, 50);

    int should_capacity = ((((CAPACITY_DEFAULT *2) * 2) * 2) *2);
    for(int i = 49; i >= 0; --i)
        remove_elem(arr, i);

    CHECK(arr->size == 0, arr->capacity == should_capacity);

    printf("test 2: remove_elem_optimize - ");
    fill_array(arr, 0, 50);

    for(int i = 49; i >= 0; --i)
        remove_elem_optimize(arr, i);
    
    CHECK(arr->size == 0, arr->capacity == 15);

    delete_array(arr);
    printf("--------------------------\n");
}

void test_clear()
{
    printf("\n-------test_clear-------\n");
    array* arr = create_array();

    printf("test 1: clear - ");
    fill_array(arr, 0, 50);

    clear_array(arr);
    CHECK(arr->size == 0, arr->capacity == CAPACITY_DEFAULT);
    
    delete_array(arr);
    printf("--------------------------\n");
}

void test_compare()
{
    printf("\n-------test_compare-------\n");
    array* arr1 = create_array();
    array* arr2 = create_array();
    array* arr3 = create_array();
    array* arr4 = create_array();

    printf("test 1: compare same - ");
    fill_array(arr1, 0, 50);
    fill_array(arr2, 0, 50);
    fill_array(arr3, 0, 1);
    fill_array(arr4, 1, 51);

    CHECK_EXPR( compare_arrays(arr1, arr2),
                "invalid compare same");

    printf("test 2: compare different size - ");
    CHECK_EXPR( !compare_arrays(arr1, arr3),
                "invalid compare different size");

    printf("test 3: compare different values - ");
    CHECK_EXPR( !compare_arrays(arr1, arr4),
                "invalid compare different values");
    
    delete_array(arr1);
    delete_array(arr2);
    delete_array(arr3);
    delete_array(arr4);
    printf("--------------------------\n");
}

void test_helpers_func()
{
    printf("\n-------test_helpers_func-------\n");
    int a = 10;
    int b = 20;
    array* arr = create_array();
    fill_array(arr, 0, 5);

    printf("test 1: swap - ");
    SWAP(a, b);

    CHECK(a == 20, b == 10);

    printf("test 2: random - ");
    {
        int temp;
        for(int i = 0; i < 100; ++i)
        {
            temp = get_rand(0, 2);
            if(!(temp <= 2 && temp >= 0))
            {
                printf("ERROR: (%d < %d)\n", temp, 3);
                return;
            } 
        }
        printf("passed\n");
    }

    delete_array(arr);
    printf("--------------------------\n");
}

void test_merge()
{
    printf("\n-------test_merge-------\n");
    array* arr1 = create_array();
    array* arr2 = create_array();
    array* arr3 = create_array();
    fill_array(arr1, 0, 50);
    fill_array(arr2, 50, 100);
    fill_array(arr3, 0, 100);

    printf("test 1: merge - ");
    array* arr4 = merge_array(arr1, arr2);

    CHECK_EXPR( compare_arrays(arr3, arr4),
                "invalid merge");
    
    delete_array(arr1);
    delete_array(arr2);
    delete_array(arr3);
    delete_array(arr4);
    printf("--------------------------\n");
}

void test_algorithms()
{
    printf("\n-------test_shuffle_fisher-------\n");
    array* arr1 = create_array();
    array* arr2 = create_array();
    array* arr3 = create_array();
    fill_array(arr1, 0, 100);
    fill_array(arr2, 0, 100);
    fill_array(arr3, 0, 100);

    printf("test 1: fisher shuffle - ");
    shuffle_fisher_array(arr1);

    if(!compare_arrays(arr1, arr2)) printf("passed\n");
    else printf("ERROR: bad fisher shuffle comapre arr1 == arr2\n");

    printf("test 2: binary search - ");
    CHECK_EXPR( binary_search_array(arr3, 10) &&
                !binary_search_array(arr3, -1),
                "invalid binary search");

    printf("test 3: default find - ");
    CHECK_EXPR( find_array(arr3, 10)  && 
                !find_array(arr3, -1) && 
                !find_array(arr3, 101),
                "invalid default find");

    printf("test 4: reverse - ");
    reverse_array(arr3);
    int bolean = TRUE;
    for(int i = 99, j = 0; i >= 0 && bolean == TRUE; --i, ++j)
        if(arr3->arr[i] != j)
            bolean = FALSE;
    CHECK_EXPR(TRUE, "invalid reverse");

    printf("test 5: qsort - ");
    qsort_array(arr1, 0, arr1->size - 1);
    CHECK_EXPR( compare_arrays(arr1, arr2),
                "invalid qsort");

    delete_array(arr1);
    delete_array(arr2);
    delete_array(arr3);
    printf("--------------------------\n");
}

void do_tests()
{
    test_removes();
    test_clear();
    test_compare();
    test_helpers_func();
    test_merge();
    test_algorithms();
}
