#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/fifo.h"

typedef struct fifo_node
{
    void *addr;
    struct fifo_node *next;
} fifo_node;

struct fifo
{
    fifo_node *first;
    fifo_node *last;
    int size;
};

FIFO *fifo_create()
{
    FIFO *fifo = (FIFO *)malloc(sizeof(FIFO));
    fifo->first = fifo->last = NULL;
    fifo->size = 0;
    return fifo;
}

bool fifo_enqueue(FIFO *fifo, void *addr)
{
    if (fifo == NULL)
        return false;
    fifo_node *node = (fifo_node *)malloc(sizeof(fifo_node));
    if (node == NULL)
        return false;
    node->addr = addr;
    node->next = NULL;
    if (fifo->first == NULL)
        fifo->first = node;
    else
        fifo->last->next = node;
    fifo->last = node;
    fifo->size++;
    return true;
}

bool fifo_dequeue(FIFO *fifo, void **receiver)
{
    if (fifo == NULL)
        return false;
    if (fifo->first == NULL)
        return false;
    fifo_node *node = fifo->first;
    fifo->first = node->next;
    if (fifo->first == NULL)
        fifo->last = NULL;
    *receiver = node->addr;
    free(node);
    fifo->size--;
    return true;
}

int fifo_size(FIFO *fifo)
{
    return fifo->size;
}

void fifo_destroy(FIFO *fifo)
{
    if (fifo != NULL)
    {
        while (fifo->first != NULL)
        {
            fifo_node *node = fifo->first;
            fifo->first = node->next;
            free(node);
        }
        free(fifo);
    }
}