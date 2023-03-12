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
