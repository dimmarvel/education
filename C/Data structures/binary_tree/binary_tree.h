#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

typedef unsigned long size_t;

typedef struct node_t
{
    int data;
    struct node_t* left;
    struct node_t* right;
} node_t;

typedef struct binary_tree
{
    size_t size;
    node_t* root;

} binary_tree;

binary_tree* create_bst();
node_t* create_node(int data);
void add_bst(binary_tree* bst, int data);
node_t* find_bst_max(binary_tree* bst);
node_t* find_bst_min(binary_tree* bst);
node_t* find_max(node_t* root);
node_t* find_min(node_t* root);
node_t* find_bst(binary_tree* bst, int elem);
void delete_bst(binary_tree* bst);
// post-order
void delete_tree(node_t* root);
// pre-order
void print_pre_ordered_bst(node_t* root);
// in-order
void print_bst(node_t* root);
int get_height(node_t* root);
void print_lvl(node_t* root, int lvl);
void bfs(node_t* root);

#define BASE_CAPASITY 10
#define INCREASE_CAPASITY 2

typedef struct queue
{
    int* que;
    size_t size;
    size_t capacity;
} queue;

queue* create_queue();
void push(queue* q, int elem);
int pop(queue* q);
size_t size_queue(queue* q);
void print_queue(queue* q);
void realloc_queue(queue* q, int size);

#endif /* _BINARY_TREE_H */
