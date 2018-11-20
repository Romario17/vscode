#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

int main()
{
    int* element;
    Stack *stack = stack_create();
    for(int i = 0; i < 10; i++)
    {
        element = (int*) malloc(sizeof(int));
        *element = i * 10;
        stack_insert(stack, element);
    }

    while(stack_size(stack) > 0)
        printf("%d ", *((int*) stack_remove(stack)));

    stack_destroy(stack);

    return EXIT_SUCCESS;
}