#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef unsigned long size_t;

typedef struct list_node
{
    int data;
    struct list_node* next;
} node_t;

typedef struct linked_list
{
    size_t size;
    node_t* head;
    node_t* last;
    node_t* iterator;
} linked_list;

linked_list* create_list();
void fill_list(linked_list* lst, int from, int to);
void delete_list(linked_list* lst);
void push_list(linked_list* lst, int data);
void print_list(linked_list* lst);

node_t* get_first(linked_list* lst);
node_t* get_next(linked_list* lst);
node_t* get_current(linked_list* lst);

#endif /* _LINKED_LIST_H */
