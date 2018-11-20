#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack Stack;

Stack *stack_create();
void stack_insert(Stack *stack, void *data);
void *stack_remove(Stack *stack);
int stack_size(Stack* stack);
void stack_destroy(Stack *stack);

#endif /* STACK_H */