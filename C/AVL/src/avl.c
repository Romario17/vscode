#include <stdio.h>
#include <stdlib.h>
#include "../include/avl.h"
#include "../include/stack.h"
#include "../include/fifo.h"

struct avl_node
{
    int key;
    void *data;
    int height;
    struct avl_node *right_child;
    struct avl_node *left_child;
};

typedef struct avl_node AVL_Node;

AVL_Tree *avl_create()
{
    AVL_Tree *avl_tree = (AVL_Tree *)malloc(sizeof(AVL_Tree));
    *avl_tree = NULL;
    return avl_tree;
}

AVL_Node *new_node(int key, void *data)
{
    AVL_Node *node = (AVL_Node *)malloc(sizeof(AVL_Node));
    node->key = key;
    node->data = data;
    node->height = 1;
    node->left_child = NULL;
    node->right_child = NULL;
    return node;
}

int max(int x, int y)
{
    if (x < y)
        return y;
    return x;
}

int height(AVL_Node *avl_node)
{
    if (avl_node == NULL)
        return 0;
    return avl_node->height;
}

int avl_height(AVL_Tree *avl_tree)
{
    return height(*avl_tree);
}

int balancing_factor(AVL_Node *avl_node)
{
    return height(avl_node->left_child) - height(avl_node->right_child);
}

/**
 * A_        |       _B_
 *   |_      |    _|    |_
 *     B_    |  A         c
 *       |_  |
 *         c |
 */
void left_rotation(AVL_Tree *a)
{
    AVL_Node *b = (*a)->right_child;
    (*a)->right_child = b->left_child;
    b->left_child = *a;
    (*a)->height = max(height((*a)->left_child), height((*a)->right_child)) + 1;
    b->height = max(height(b->left_child), height(b->right_child)) + 1;
    *a = b;
}

/**
 *          _A |      _B_
 *        _|   |   _|    |_
 *     _B      | c         A
 *   _|        |
 * c           |
 */
void right_rotation(AVL_Tree *a)
{
    AVL_Node *b = (*a)->left_child;
    (*a)->left_child = b->right_child;
    b->right_child = *a;
    (*a)->height = max(height(((*a)->left_child)), height((*a)->right_child)) + 1;
    b->height = max(height(b->left_child), height(b->right_child)) + 1;
    *a = b;
}

/**
 *  A_    | A_         |      _C_
 *    |_  |   |_       |   _|    |_
 *     _B |     C_     |  A        B
 *   _|   |       |_   |
 *  C     |         B  | 
 */
void dleft_rotation(AVL_Tree *a)
{
    right_rotation(&(*a)->right_child);
    left_rotation(a);
}

/**
 *    _ A |         _ A  |      _C_
 *  _|    |       _|     |   _|    |_
 * B_     |     _C       | B         A
 *   |_   |   _|         |
 *      C | B            |
 */
void dright_rotation(AVL_Tree *a)
{
    left_rotation(&(*a)->left_child);
    right_rotation(a);
}

void *avl_search(AVL_Tree *avl_tree, int key)
{
    if (*avl_tree == NULL)
    {
        printf("empty tree!!!\n");
        return NULL;
    }
    AVL_Node *searched_node = *avl_tree;
    bool end_of_search = false;
    void *searched_data = NULL;
    do
    {
        if (key < searched_node->key)
            searched_node = searched_node->left_child;
        else if (key > searched_node->key)
            searched_node = searched_node->right_child;
        else
        {
            searched_data = searched_node->data;
            end_of_search = true;
        }
        if (searched_node == NULL)
            end_of_search = true;
    } while (!end_of_search);
    return searched_data;
}

bool avl_insert(AVL_Tree *avl_tree, int key, void *data)
{
    if (*avl_tree == NULL)
    {
        *avl_tree = new_node(key, data);
        return true;
    }

    Stack *stack = stack_create();
    bool successful_insertion = false;
    bool end_of_insertion = false;
    AVL_Node **ptr_insert_node = avl_tree;

    while (!end_of_insertion)
    {
        if (key == (*ptr_insert_node)->key)
        {
            printf("repeated key!!!\n");
            end_of_insertion = true;
        }
        else
        {
            stack_insert(stack, ptr_insert_node);
            if (key < (*ptr_insert_node)->key)
                ptr_insert_node = &(*ptr_insert_node)->left_child;
            else
                ptr_insert_node = &(*ptr_insert_node)->right_child;
        }
        if (*ptr_insert_node == NULL)
        {
            *ptr_insert_node = new_node(key, data);
            successful_insertion = true;
            end_of_insertion = true;
        }
    }

    AVL_Node **balancing_node;
    while (stack_size(stack) > 0)
    {
        balancing_node = (AVL_Node **)stack_remove(stack);
        if (balancing_factor(*balancing_node) >= 2)
            if (height((*balancing_node)->left_child) > height((*balancing_node)->right_child))
                right_rotation(balancing_node);
            else
                dright_rotation(balancing_node);

        else if (balancing_factor(*balancing_node) <= -2)
            if (height((*balancing_node)->right_child) > height((*balancing_node)->left_child))
                left_rotation(balancing_node);
            else
                dleft_rotation(balancing_node);

        else
            (*balancing_node)->height = max(height((*balancing_node)->left_child), height((*balancing_node)->right_child)) + 1;
    }

    stack_destroy(stack);
    return successful_insertion;
}

AVL_Node *minor_search(AVL_Node *avl_node)
{
    while (avl_node->left_child != NULL)
        avl_node = avl_node->left_child;
    return avl_node;
}

bool avl_remove(AVL_Tree *avl_tree, int key)
{
    if (*avl_tree == NULL)
    {
        printf("Empty Tree!!!\n");
        return false;
    }

    Stack *stack = stack_create();
    bool successful_removal = false;
    bool end_of_removal = false;
    AVL_Node **ptr_searched_node = avl_tree;
    AVL_Node *removal_node = NULL;

    while (!end_of_removal)
    {
        if (key != (*ptr_searched_node)->key)
            stack_insert(stack, ptr_searched_node);
        if (key < (*ptr_searched_node)->key)
            ptr_searched_node = &(*ptr_searched_node)->left_child;
        else if (key > (*ptr_searched_node)->key)
            ptr_searched_node = &(*ptr_searched_node)->right_child;
        else
        {
            if ((*ptr_searched_node)->left_child == NULL || (*ptr_searched_node)->right_child == NULL)
            {
                removal_node = *ptr_searched_node;
                if ((*ptr_searched_node)->left_child != NULL)
                    *ptr_searched_node = (*ptr_searched_node)->left_child;
                else
                    *ptr_searched_node = (*ptr_searched_node)->right_child;
                free(removal_node);
                successful_removal = true;
                end_of_removal = true;
            }
            else
            {
                AVL_Node *minor = minor_search((*ptr_searched_node)->right_child);
                (*ptr_searched_node)->key = minor->key;
                (*ptr_searched_node)->data = minor->data;
                key = minor->key;
                ptr_searched_node = &(*ptr_searched_node)->right_child;
            }
        }
        if ((*ptr_searched_node == NULL) && (successful_removal == false))
        {
            printf("key not found!!!\n");
            end_of_removal = true;
        }
    }

    AVL_Node **balancing_node;
    while (stack_size(stack) > 0)
    {
        balancing_node = (AVL_Node **)stack_remove(stack);
        if (balancing_factor(*balancing_node) >= 2)
            if (height((*balancing_node)->left_child) > height((*balancing_node)->right_child))
                right_rotation(balancing_node);
            else
                dright_rotation(balancing_node);

        else if (balancing_factor(*balancing_node) <= -2)
            if (height((*balancing_node)->right_child) > height((*balancing_node)->left_child))
                left_rotation(balancing_node);
            else
                dleft_rotation(balancing_node);

        else
            (*balancing_node)->height = max(height((*balancing_node)->left_child), height((*balancing_node)->right_child)) + 1;
    }
    stack_destroy(stack);
    return successful_removal;
}

void print(AVL_Node *avl_node, int height)
{
    if (avl_node != NULL)
    {
        print(avl_node->right_child, height + 1);
        printf("%*d\n", height * 5, avl_node->key);
        print(avl_node->left_child, height + 1);
    }
}

void avl_print(AVL_Tree *avl_tree)
{
    print(*avl_tree, 0);
}

void avl_print_inlevel(AVL_Tree* avl_tree)
{
    if(avl_tree == NULL || *avl_tree == NULL)
        return;

    AVL_Node* avl_node = *avl_tree;
    Fifo *fifo = fifo_create();
    fifo_enqueue(fifo, avl_node);

    while(fifo_size(fifo) > 0)
    {
        fifo_dequeue(fifo, (void **)&avl_node);
        printf("%d ", avl_node->key);
        if(avl_node->left_child) fifo_enqueue(fifo, avl_node->left_child);
        if(avl_node->right_child) fifo_enqueue(fifo, avl_node->right_child);
    }
    printf("\n");
}

void avl_print_preorder(AVL_Tree* avl_tree)
{
    if(avl_tree == NULL || *avl_tree == NULL)
        return;
    AVL_Node* avl_node = *avl_tree;    
    Stack *stack = stack_create();
    stack_insert(stack, avl_node);
    while(stack_size(stack) > 0)
    {
        avl_node = stack_remove(stack);
        printf("%d ", avl_node->key);
        if(avl_node->right_child) stack_insert(stack, avl_node->right_child);
        if(avl_node->left_child) stack_insert(stack, avl_node->left_child);
    }
    stack_destroy(stack);
    printf("\n");
}

void avl_print_inorder(AVL_Tree* avl_tree)
{
    if(avl_tree == NULL || *avl_tree == NULL)
        return;
    
    AVL_Node* avl_node = *avl_tree;    
    Stack *stack = stack_create();
    
    while(avl_node != NULL || stack_size(stack) > 0)
    {
        if(avl_node != NULL)
        {
            stack_insert(stack, avl_node);
            avl_node = avl_node->left_child;
        }
        else
        {
            avl_node = stack_remove(stack);
            printf("%d ", avl_node->key);
            avl_node = avl_node->right_child;
        }
    }
    
    stack_destroy(stack);
    printf("\n");
}

void avl_print_postorder(AVL_Tree* avl_tree)
{
    if(avl_tree == NULL)
        return;
    if(*avl_tree != NULL)
    {
        avl_print_postorder(&(*avl_tree)->left_child);
        avl_print_postorder(&(*avl_tree)->right_child);
        printf("%d ", (*avl_tree)->key);
    }
}

void destroy_nodes(AVL_Node* avl_node)
{
    if(avl_node == NULL)
        return;
    destroy_nodes(avl_node->left_child);
    destroy_nodes(avl_node->right_child);
    free(avl_node);
    avl_node = NULL;
}

void avl_destroy(AVL_Tree *avl_tree)
{
    if(avl_tree == NULL)
        return;
    destroy_nodes(*avl_tree);
    free(avl_tree);
}