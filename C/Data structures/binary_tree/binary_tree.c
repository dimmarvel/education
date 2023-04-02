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
    node_t* temp = malloc(sizeof(node_t));
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

    insert_bst(bst->root, data);
}

void delete_tree(node_t* root)
{
    if(!root) return;
    
    if(root->left) delete_tree(root->left);
    if(root->right) delete_tree(root->right);

    free(root);
}

void delete_bst(binary_tree* bst)
{
    if(!bst) return;

    delete_tree(bst->root); 
    free(bst);
}

node_t* find_bst_max(binary_tree* bst)
{
    if(!bst || !bst->root) return NULL;
    return find_max(bst->root);
}

node_t* find_bst_min(binary_tree* bst)
{
    if(!bst || !bst->root) return NULL;
    return find_min(bst->root);
}

node_t* find_max(node_t* root)
{
    if(!root) return NULL;
    node_t* find_elem = root;
    while(find_elem->right) find_elem = find_elem->right;
    return find_elem;
}

node_t* find_min(node_t* root)
{
    if(!root) return NULL;
    node_t* find_elem = root;
    while(find_elem->left) find_elem = find_elem->left;
    return find_elem;
}

node_t* find(node_t* root, int elem)
{
    if(!root) return NULL;
    if(elem == root->data) return root;
    if(elem < root->data) return find(root->left, elem);
    if(elem > root->data) return find(root->right, elem);
    return NULL;
}

node_t* find_bst(binary_tree* bst, int elem)
{
    if(!bst) return NULL;
    if(!bst->root) return NULL;
    return find(bst->root, elem);
}

void print_bst(node_t* root)
{
    if(!root) return;
    print_bst(root->left);
    printf("%d\n", root->data);
    print_bst(root->right);
}
