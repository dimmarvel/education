#ifndef _ARRAY_H
#define _ARRAY_H

#define CAPACITY_INCREACE(arr) ((int)(arr->capacity * 2))
#define CAPACITY_DEFAULT 5
#define CAPACITY_OPTIMIZE 1.5
#define CAPACITY_OPTIMIZE_START (CAPACITY_DEFAULT * 2)
#define ERROR(info) { printf("ERROR: %s\n", info); exit(1); }

typedef unsigned long size_t;

typedef struct array
{
    size_t capacity;
    size_t size;
    int* arr;
} array;

array* create_array();

// base functions
void realloc_array(array* arr, int size);
void remove_elem(array* arr, int index);
void remove_elem_optimize(array* arr, int index);
void clear_array(array* arr);
void add(array* arr, int element);
void delete_array(array *arr);
int compare_arrays(array* first, array* second);
void print_array(array *arr);
void fill_array(array* arr, int from, int to);
void print_array(array *arr);
// Fisher–Yates shuffle algorithm
void shuffle_fisher_array(array* arr);


#endif /* _ARRAY_H */
