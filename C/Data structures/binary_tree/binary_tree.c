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

void print_pre_ordered_bst(node_t* root)
{
    if(!root) return;
    printf("%d\n", root->data);
    print_bst(root->left);
    print_bst(root->right);
}

int get_height(node_t* root)
{
    if(!root) return 0;
    int height_l = get_height(root->left);
    int height_r = get_height(root->right);
    return (height_l > height_r) ? height_l + 1 : height_r + 1;
}

void bfs(node_t* root)
{
    int h = get_height(root);
    for(int i = 0; i < h; i++)
        print_lvl(root, i);
}

void print_lvl(node_t* root, int lvl)
{
    if(!root) return;
    if(lvl == 0) 
    {
        printf("%d ", root->data);
    }
    else
    {
        print_lvl(root->left, lvl - 1);
        print_lvl(root->right, lvl - 1);
    }
}

queue* create_queue()
{
    queue* q = malloc(sizeof(queue));
    q->que = malloc(sizeof(int) * BASE_CAPASITY);
    q->capacity = BASE_CAPASITY;
    q->size = 0;
    return q;
}

void realloc_queue(queue* q, int size)
{
    int* new_que = realloc(q->que, size * sizeof(int));
    if(new_que == NULL) ERROR("bad realloc array");
    q->que = new_que;
}

void push(queue* q, int elem)
{
    if(q->size == q->capacity)
    {
        q->capacity *= INCREASE_CAPASITY;
        realloc_queue(q, q->capacity);
    }
    q->que[q->size++] = elem;
}

int pop(queue* q)
{
    return q->que[--q->size];
}

size_t size_queue(queue* q)
{
    return q->size;
}

void print_queue(queue* q)
{
    for(int i = 0; i < q->size; ++i)
        printf("%d) %d", i, q->que[i]);
}

