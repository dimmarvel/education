#include "stack.h"
#include "../helpers.h"
#include <stdio.h>
#include <stdlib.h>

stack* create_stack()
{
    stack* temp = malloc(sizeof(stack));
    temp->capacity = CAPACITY_DEFAULT;
    temp->top = 0;
    temp->arr = malloc(temp->capacity * sizeof(int));
    return temp;
}

void realloc_stack(stack* stk, int size)
{
    int* new_stk = realloc(stk->arr, size * sizeof(int));
    if(new_stk == NULL) ERROR("bad realloc stack");
    stk->arr = new_stk;
}

void push(stack* stk, int num)
{
    if(stk->capacity == stk->top)
    {
        stk->capacity = CAPACITY_INCREACE(stk);
        realloc_stack(stk, stk->capacity);
    }
    stk->arr[stk->top++] = num;
}

int pop(stack* stk)
{
    if(stk->top == 0) ERROR("pop: stack size out of range");

    if(stk->top < CAPACITY_OPTIMIZE_START) return stk->arr[--stk->top];

    if((((int)stk->capacity / 2) >= stk->top))
    {
        stk->capacity = (int)(stk->capacity / CAPACITY_OPTIMIZE);
        realloc_stack(stk, stk->capacity);
    }

    return stk->arr[--stk->top];
}

void fill_stack(stack* stk, int from, int to)
{
    for(int i = from; i < to; ++i)
        push(stk, i);
}

void delete_stack(stack* stk)
{
    free(stk->arr);
    free(stk);
}

void print_stack(stack *stk)
{
    printf( "stack: \n - address %p \n - size %ld \n - capacity %ld \n", 
            stk, stk->top, stk->capacity);
            
    if(stk->top != 0)
    {
        printf("elements: ");
        for(size_t i = 0; i < stk->top; ++i)
            printf("%d ", stk->arr[i]);
    }
    printf("\n");
}
