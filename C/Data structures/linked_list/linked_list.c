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

void delete_list(linked_list* lst)
{
    if(lst == NULL) return;
    if(lst->head == NULL)
    {
        free(lst);
        return;
    }

    node_t* current = lst->head;
    while(current)
    {
        node_t* del_node = current;
        current = current->next;
        free(del_node);
    }
    free(lst);
}

void push_list(linked_list* lst, int data)
{
    if(lst->head == NULL)
    {
        lst->head = malloc(sizeof(node_t));
        ++lst->size;
        lst->head->data = data;
        lst->head->next = NULL;
        return;
    }

    if(lst->head != NULL && lst->last == NULL)
    {
        lst->last = malloc(sizeof(node_t));
        lst->head->next = lst->last;
        ++lst->size;
        lst->last->data = data;
        lst->last->next = NULL;
        return;
    }
    
    lst->last->next = malloc(sizeof(node_t));
    lst->size++;
    lst->last = lst->last->next;
    lst->last->data = data;
    lst->last->next = NULL;
}

node_t* find_list(linked_list* lst, int number)
{
    if(!lst || lst->size <= 0) ERROR("bad list");
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
            if(next->next == NULL)
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
    
    printf("\n");
}
