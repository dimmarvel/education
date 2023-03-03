#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void test_removes()
{
    printf("\n-------test_removes-------\n");
    array* arr = create_array();

    printf("test 1: remove_elem - ");
    for(int i = 0; i < 50; i++)
        add(arr, i);

    int should_capacity = ((((CAPACITY_DEFAULT *2) * 2) * 2) *2);
    for(int i = 49; i >= 0; i--)
        remove_elem(arr, i);

    if(arr->size == 0 && arr->capacity == should_capacity) printf("passed\n");
    else printf("ERROR: (%d == %d && %d == %d)\n", arr->size, 0, arr->capacity, should_capacity);
    

    printf("test 2: remove_elem_optimize - ");
    for(int i = 0; i < 50; i++)
        add(arr, i);

    for(int i = 49; i >= 0; i--)
        remove_elem_optimize(arr, i);
    
    if(arr->size == 0 && arr->capacity == 15) printf("passed\n");
    else printf("ERROR: (%d == %d && %d == %d)\n", arr->size, 0, arr->capacity, 15);

    delete_array(arr);
    printf("--------------------------\n");
}

int main(int argc, int** argv)
{
    test_removes();
    return 0;
}
