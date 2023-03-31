#include "binary_tree.h"
#include "../helpers.h"
#include <stdio.h>
#include <stdlib.h>

binary_tree* create_bst()
{
    binary_tree* temp = malloc(sizeof(binary_tree));
    temp->size = 0;
    temp->root = NULL;
    return temp;
}

node_t* create_node(int data)
{
    node_t* temp = malloc(sizeof(node_t*));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node_t* insert_bst(node_t* node, int data)
{
    if(node == NULL) return create_node(data);

    if(data < node->data)
        node->left = insert_bst(node->left, data);
    else
        node->right = insert_bst(node->right, data);

    return node;
}

void add_bst(binary_tree* bst, int data)
{
    if(!bst) ERROR("binary tree is null");
    
    if(!bst->root)
    {
        bst->root = create_node(data);
        return;
    }

    bst->root = insert_bst(bst->root, data);
}

void fill_bst(binary_tree* bst)
{
    add_bst(bst, 10);
    add_bst(bst, 0);
    add_bst(bst, 11);
    add_bst(bst, 14);
    add_bst(bst, 13);
    add_bst(bst, 7);
}

void print_bst(node_t* root)
{
    if(!root) return;
    print_bst(root->left);
    printf("%d\n", root->data);
    print_bst(root->right);
}
