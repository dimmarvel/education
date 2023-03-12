#ifndef _STACK_H
#define _STACK_H

#define CAPACITY_DEFAULT 5
#define CAPACITY_OPTIMIZE 1.5
#define CAPACITY_INCREACE(stk) ((int)(stk->capacity * 2))
#define CAPACITY_OPTIMIZE_START (CAPACITY_DEFAULT * 2)

typedef unsigned long size_t;

typedef struct stack
{
    int* arr;
    size_t capacity;
    size_t top;
} stack;

stack* create_stack();
void push(stack* stk, int num);
int pop(stack* stk);
void fill_stack(stack* stk, int from, int to);
void realloc_stack(stack* stk, int size);
void delete_stack(stack* stk);
void print_stack(stack *stk);

#endif /* _STACK_H */
