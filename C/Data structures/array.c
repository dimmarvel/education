#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY_INCREACE(arr) ((int)(arr->capacity * 2))
#define CAPACITY_DEFAULT 5
#define CAPACITY_OPTIMIZE 1.5
#define CAPACITY_OPTIMIZE_START (CAPACITY_DEFAULT * 2)
#define ERROR(info) { printf("ERROR: %s\n", info); exit(1); }

typedef struct array array;
void print_array(array *arr);

typedef struct array
{
    int capacity;
    int size;
    int* arr;
} array;

array* create_array()
{
    array* arr = malloc(sizeof(array));
    arr->capacity = CAPACITY_DEFAULT;
    arr->size = 0;
    arr->arr = malloc(arr->capacity * sizeof(int));
    return arr;
}

void realloc_array(array* arr, int size)
{
    int* new_arr = realloc(arr->arr, size * sizeof(int));
    if(new_arr == NULL) ERROR("bad realloc array");
    arr->arr = new_arr;
}

void remove_elem(array* arr, int index)
{
    if(index < 0 || index >= arr->size) ERROR("index out of range when remove");

    if(index == arr->size - 1)
    {
        --arr->size;
        return;
    }

    for(int i = 0; i < arr->size; ++i)
        if(i > index)
            arr->arr[i-1] = arr->arr[i];
    --arr->size;
}

void remove_elem_optimize(array* arr, int index)
{
    remove_elem(arr, index);
    
    if(arr->size < CAPACITY_OPTIMIZE_START) return;

    if((((int)arr->capacity / 2) >= arr->size))
    {
        arr->capacity = (int)(arr->capacity / CAPACITY_OPTIMIZE);
        realloc_array(arr, arr->capacity);
    }
}

void clear_array(array* arr)
{
    if(arr->capacity < CAPACITY_DEFAULT || arr->size == 0) return;
    arr->capacity = CAPACITY_DEFAULT;
    arr->size = 0;
    realloc_array(arr, arr->capacity);
}

void add(array* arr, int element)
{
    if(arr->size < arr->capacity)
    {
        arr->arr[arr->size++] = element;
        return;
    }
    
    arr->capacity = CAPACITY_INCREACE(arr);
    realloc_array(arr, arr->capacity);
    arr->arr[arr->size++] = element;
}

void delete_array(array *arr)
{
    free(arr->arr);
    free(arr);
}

int compare_arrays(array* first, array* second)
{
    if(first->size != second->size) return 0;

    for(int i = 0; i < first->size; ++i)
        if(first->arr[i] != second->arr[i]) 
            return 0;
    return 1;
}

void print_array(array *arr)
{
    printf("array: \n - address %p \n - size %d \n - capacity %d \n", arr, arr->size, arr->capacity);
    if(arr->size != 0)
    {
        printf("elements: ");
        for(int i = 0; i < arr->size; ++i)
            printf("%d ", arr->arr[i]);
    }
    printf("\n");
}

void fill_array(array* arr, int from, int to)
{
    for(int i = from; i < to; ++i)
        add(arr, i);
}

void test_removes()
{
    printf("\n-------test_removes-------\n");
    array* arr = create_array();

    printf("test 1: remove_elem - ");
    fill_array(arr, 0, 50);

    int should_capacity = ((((CAPACITY_DEFAULT *2) * 2) * 2) *2);
    for(int i = 49; i >= 0; --i)
        remove_elem(arr, i);

    if(arr->size == 0 && arr->capacity == should_capacity) printf("passed\n");
    else printf("ERROR: (%d == %d && %d == %d)\n", arr->size, 0, arr->capacity, should_capacity);
    

    printf("test 2: remove_elem_optimize - ");
    fill_array(arr, 0, 50);

    for(int i = 49; i >= 0; --i)
        remove_elem_optimize(arr, i);
    
    if(arr->size == 0 && arr->capacity == 15) printf("passed\n");
    else printf("ERROR: (%d == %d && %d == %d)\n", arr->size, 0, arr->capacity, 15);

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

    if(arr->size == 0 && arr->capacity == CAPACITY_DEFAULT) printf("passed\n");
    else printf("ERROR: (%d == %d && %d == %d)\n", arr->size, 0, arr->capacity, CAPACITY_DEFAULT);
    
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

    if(compare_arrays(arr1, arr2)) printf("passed\n");
    else printf("ERROR: bad comapre arr1 != arr2\n");

    printf("test 2: compare different size - ");
    if(!compare_arrays(arr1, arr3)) printf("passed\n");
    else printf("ERROR: bad comapre arr1 == arr3\n");

    printf("test 3: compare different values - ");
    if(!compare_arrays(arr1, arr4)) printf("passed\n");
    else printf("ERROR: bad comapre arr1 == arr4\n");
    
    delete_array(arr1);
    delete_array(arr2);
    delete_array(arr3);
    delete_array(arr4);
    printf("--------------------------\n");
}

int main(int argc, int** argv)
{
    test_removes();
    test_clear();
    test_compare();
    return 0;
}
