#include "linked_list.h"
#include "../helpers.h"
#include <stdio.h>
#include <stdlib.h>

linked_list* create_list()
{
    linked_list* temp = malloc(sizeof(linked_list));
    temp->size = 0;
    temp->head = NULL;
    temp->last = NULL;
    return temp;
}

void clear_list(linked_list* lst)
{
    if(!lst || !lst->head) return;
    while(lst->head)
    {
        node_t* del_node = lst->head;
        lst->head = lst->head->next;
        free(del_node);
        --lst->size;
    }
}

void delete_list(linked_list* lst)
{
    if(!lst) return;
    if(!lst->head)
    {
        free(lst);
        return;
    }

    while(lst->head)
    {
        node_t* del_node = lst->head;
        lst->head = lst->head->next;
        free(del_node);
    }
    free(lst);
}

void push_list(linked_list* lst, int data)
{
    if(!lst->head)
    {
        lst->head = malloc(sizeof(node_t));
        ++lst->size;
        lst->head->data = data;
        lst->head->next = NULL;
        return;
    }

    if(lst->head && !lst->last)
    {
        lst->last = malloc(sizeof(node_t));
        lst->head->next = lst->last;
        ++lst->size;
        lst->last->data = data;
        lst->last->next = NULL;
        return;
    }
    
    lst->last->next = malloc(sizeof(node_t));
    ++lst->size;
    lst->last = lst->last->next;
    lst->last->data = data;
    lst->last->next = NULL;
}

node_t* find_list(linked_list* lst, int number)
{
    if(!lst || lst->size <= 0) return NULL;
    for(node_t* curr = get_first(lst); get_current(lst); curr = get_next(lst))
        if(curr->data == number)
            return curr;
    return NULL;
}

void remove_list(linked_list* lst, int index)
{
    if(!lst || lst->size <= 0 || lst->size < index) ERROR("index out of range or list size == 0");
    if(lst->size == 1)
    {
        free(lst->last);
        free(lst->head);
        --lst->size;
    }

    int i = 1;
    node_t* prev = get_first(lst);
    node_t* next = get_next(lst);
    while(TRUE)
    {
        if(i == index)
        {
            if(!next->next)
            {
                --lst->size;
                prev->next = NULL;
                free(next);
                return;
            }
            prev->next = NULL;
            --lst->size;
            free(next);
            return;
        }
        prev = next;
        next = get_next(lst);
        ++i;
    }
}

node_t* get_first(linked_list* lst)
{
    if(!lst->head) return NULL;
    lst->iterator = lst->head;
    return lst->head;
}

node_t* get_next(linked_list* lst)
{
    if(!lst->iterator) return NULL;
    lst->iterator = lst->iterator->next;
    return lst->iterator;
}

node_t* get_current(linked_list* lst)
{
    return lst->iterator;
}

void fill_list(linked_list* lst, int from, int to)
{
    for(int i = from; i < to; ++i)
        push_list(lst, i);
}

linked_list* split_half_list(linked_list* lst)
{
    if(lst->size <= 1) ERROR("invalid size");

    linked_list* half = create_list();
    int half_size = lst->size / 2;
    node_t* curr;
    curr = get_first(lst);
    for(int i = 1; i < half_size; ++i)
        curr = get_next(lst);

    half->head = curr->next;
    curr->next = NULL;
    half->last = curr;
    half->size = (lst->size - half_size) - 1;
    lst->size = half_size;
    return half;
}

void interleave_list(linked_list* first_half, linked_list* second_half)
{
    node_t* tail = NULL;
    node_t* frst_half = first_half->head;
    node_t* scnd_half = second_half->head;
    while(scnd_half && scnd_half)
    {
        if(!tail) tail = scnd_half;
        else tail->next = scnd_half;
        
        node_t* next = scnd_half->next;
        scnd_half->next = frst_half;
        scnd_half = next;
        tail = frst_half;

        next = frst_half->next;
        frst_half->next = NULL;
        frst_half = next;
    }
}

void shuffle_list(linked_list* head) 
{
    if (head == NULL) return;
    linked_list* half = split_half_list(head);
    interleave_list(half, head);
    head = half;
    free(half);
}

void print_list(linked_list* lst)
{
    printf( "list: \n - list address %p \n - size %ld \n", 
            lst, lst->size);
    
    printf("\n elements:\n");

    node_t* current = lst->head;
    while(current)
    {
        printf("node:\n - address: %p\n - next address: %p \n - data: %d \n",
                    current, current->next, current->data);
        current = current->next;
    }

    current = lst->head;
    while(current)
    {
        printf("%d->", current->data);
        current = current->next;
        if(!current) printf("NULL\n");
    }
    
    printf("\n");
}
