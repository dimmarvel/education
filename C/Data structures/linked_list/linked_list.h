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
node_t* find_list(linked_list* lst, int number);
void remove_list(linked_list* lst, int index);
void clear_list(linked_list* lst);
linked_list* split_half_list(linked_list* lst);
void shuffle_list(linked_list* head);
int compare_list(linked_list* first, linked_list* second);
void interleave_list(linked_list* first_half, linked_list* second_half);
void reverse_list(linked_list* lst);
void swap_data_list(node_t* first, node_t* second);

node_t* get_first(linked_list* lst);
node_t* get_next(linked_list* lst);
node_t* get_current(linked_list* lst);

#endif /* _LINKED_LIST_H */
