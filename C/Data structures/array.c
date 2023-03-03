#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY_INCREACE(arr) ((int)(arr->capacity * 2))
#define CAPACITY_DEFAULT 5
#define ERROR(info) printf("error: %s\n", info); exit(1)

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

void print_array(array *arr)
{
    printf("array, size - %d, capacity - %d\n", arr->size, arr->capacity);
    for(int i = 0; i < arr->size; ++i)
        printf("%d ", arr->arr[i]);
    printf("\n");
}

void realloc_array(array* arr, int size)
{
    int* new_arr = realloc(arr->arr, size * sizeof(int));
    if(new_arr == NULL) { ERROR("bad realloc array"); }
    arr->arr = new_arr;
}

void remove_elem(array* arr, int index)
{
    if(index < 0 || index >= arr->size) { ERROR("index out of range when remove"); }

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

int main(int argc, int** argv)
{
    array* arr = create_array();

    print_array(arr);
    for(int i = 0; i < 100; i++)
        add(arr, i);
    for(int i = 99; i >= 0; i--)
        remove_elem(arr, i);
    print_array(arr);

    delete_array(arr);
    return 0;
}