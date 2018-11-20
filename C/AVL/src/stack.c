#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

typedef struct stack_node
{
    void* data;
    struct stack_node* next;
} Stack_Node;

struct stack
{
    Stack_Node* top;
    int size;
};

Stack* stack_create()
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void stack_insert(Stack* stack, void* data)
{
    Stack_Node* node = (Stack_Node*) malloc(sizeof(Stack_Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

void* stack_remove(Stack* stack)
{
    if(stack->top == NULL)
        return NULL;
    Stack_Node* node = stack->top;
    void* data = node->data;
    stack->top = stack->top->next;
    free(node);
    stack->size--;
    return data;
}

int stack_size(Stack* stack)
{
    return stack->size;
}

void stack_destroy(Stack* stack)
{
    Stack_Node* node;
    while(stack->top != NULL)
    {
        node = stack->top;
        stack->top = stack->top->next;
        free(node);
    }
    free(stack);
}