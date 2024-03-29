#include "array.h"
#include "../helpers.h"
#include <stdio.h>
#include <string.h>

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

    for(size_t i = 0; i < arr->size; ++i)
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

// Fisher–Yates shuffle algorithm
void shuffle_fisher_array(array* arr)
{
    if(arr->size <= 1) return;

    for(size_t i = 0; i < arr->size; ++i)
    {
        int rnd = get_rand(0, arr->size);
        SWAP(arr->arr[i], arr->arr[rnd]);
    }
}

int compare_arrays(array* first, array* second)
{
    if(first->size != second->size) return 0;

    for(size_t i = 0; i < first->size; ++i)
        if(first->arr[i] != second->arr[i]) 
            return 0;
    return 1;
}

array* merge_array(array* first, array* second)
{
    array* new_array = malloc(sizeof(array));
    new_array->capacity = CAPACITY_INCREACE_MERGE(first, second);
    new_array->size = first->size + second->size;
    new_array->arr = malloc(new_array->capacity * sizeof(int));

    for(size_t i = 0; i < first->size; ++i)
        new_array->arr[i] = first->arr[i];
    for(size_t i = first->size, j = 0; j < second->size; ++i, ++j)
        new_array->arr[i] = second->arr[j];

    return new_array;
}

int find_array(array* arr, int number)
{
    if(arr->size == 0) return FALSE;

    for(int i = 0; i < arr->size; i++)
        if(arr->arr[i] == number)
            return i;
    return FALSE;
}

int binary_search_array(array* arr, int number)
{
    if(arr->size == 0) return FALSE;

    int min = 0;
    int max = arr->size - 1;
    int middle = 0;
    
    while(min <= max)
    {
        middle = (int)((min + max) / 2);
        if(number < arr->arr[middle])
            max = middle - 1;
        else if(number > arr->arr[middle])
            min = middle + 1;
        else
            return TRUE;
    }
    return FALSE;
}

void reverse_array(array* arr)
{
    if(arr->size <= 1) return;

    for(int i = 0; i < (int)(arr->size / 2); ++i)
        SWAP(arr->arr[i], arr->arr[arr->size - i - 1]);
}

int partition(array* arr, int left, int right)
{
    int pivot = arr->arr[left + (right - left) / 2];
    while(TRUE)
    {
        while(arr->arr[left] < pivot) left++;
        while(arr->arr[right] > pivot) right--;
        if(left >= right) return right;
        SWAP(arr->arr[left], arr->arr[right]);
        left++;
        right--;
    }
}

// Hoare Partition
void qsort_array(array* arr, int left, int right)
{
    if(arr->size <= 1) return;
    if(left < right)
    {
        int patr = partition(arr, left, right);
        qsort_array(arr, left, patr);
        qsort_array(arr, patr + 1, right);
    }
}

void print_array(array *arr)
{
    printf( "array: \n - address %p \n - size %ld \n - capacity %ld \n", 
            arr, arr->size, arr->capacity);
            
    if(arr->size != 0)
    {
        printf("elements: ");
        for(size_t i = 0; i < arr->size; ++i)
            printf("%d ", arr->arr[i]);
    }
    printf("\n");
}

void fill_array(array* arr, int from, int to)
{
    for(int i = from; i < to; ++i)
        add(arr, i);
}
