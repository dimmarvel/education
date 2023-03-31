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
void fill_bst(binary_tree* bst);
void print_bst(node_t* root);

#endif /* _BINARY_TREE_H */
