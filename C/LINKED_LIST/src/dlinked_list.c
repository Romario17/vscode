#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/dlinked_list.h"

typedef struct dlinked_list_node
{
    void *addr;
    struct dlinked_list_node *previous;
    struct dlinked_list_node *next;
} DLinkedListNode;

struct dlinked_list
{
    DLinkedListNode *first;
    DLinkedListNode *last;
    DLinkedListNode *current; // current searched node
    int size;
};

DLinkedListNode *dlinkedListNode_new(void *addr)
{
    DLinkedListNode *node = (DLinkedListNode *)malloc(sizeof(DLinkedListNode));
    node->addr = addr;
    node->previous = node->next = NULL;
    return node;
}

DLinkedList *linkedList_create()
{
    DLinkedList *dlinked_list = (DLinkedList *)malloc(sizeof(DLinkedList));
    dlinked_list->first =
        dlinked_list->last =
            dlinked_list->current = NULL;
    dlinked_list->size = 0;
    return dlinked_list;
}

void dlinkedList_insertFirst(DLinkedList *dlinked_list, void *addr)
{
    DLinkedListNode *node = dlinkedListNode_new(addr);
    if (dlinked_list->first == NULL)
        dlinked_list->first = dlinked_list->last = node;
    else
    {
        node->next = dlinked_list->first;
        dlinked_list->first->previous = node;
        dlinked_list->first = node;
    }
    dlinked_list->size++;
}

void dlinkedList_insertLast(DLinkedList *dlinked_list, void *addr)
{
    DLinkedListNode *node = dlinkedListNode_new(addr);
    if (dlinked_list->first == NULL)
        dlinked_list->first = dlinked_list->last = node;
    else
    {
        node->previous = dlinked_list->last;
        dlinked_list->last->next = node;
        dlinked_list->last = node;
    }
    dlinked_list->size++;
}

void *dlinkedList_removeFirst(DLinkedList *dlinked_list)
{
    if (dlinked_list->first == NULL)
        return NULL;
    if (dlinked_list->first == dlinked_list->last)
        dlinked_list->last = NULL;
    DLinkedListNode *node = dlinked_list->first;
    void *addr = node->addr;
    dlinked_list->first = dlinked_list->first->next;
    dlinked_list->first->previous = NULL;
    free(node);
    dlinked_list->size--;
    return addr;
}

void *dlinkedList_removeLast(DLinkedList *dlinked_list)
{
    if (dlinked_list->first == NULL)
        return NULL;
    if (dlinked_list->last == dlinked_list->first)
        dlinked_list->first = NULL;
    DLinkedListNode *node = dlinked_list->last;
    void *addr = node->addr;
    dlinked_list->last = dlinked_list->last->previous;
    dlinked_list->last->next = NULL;
    free(node);
    dlinked_list->size--;
    return addr;
}

bool dlinkedList_itrInsertCurrent(DLinkedList *dlinked_list, void *addr)
{
    if (dlinked_list->current == NULL)
        return false;
    DLinkedListNode *node = dlinkedListNode_new(addr);
    node->next = dlinked_list->current;
    node->previous = dlinked_list->current->previous;
    if(node->previous != NULL)
        node->previous->next = node;
    node->next->previous = node;
    dlinked_list->size++;
    dlinked_list->current = NULL;
    return true;    
}

bool dlinkedList_itrRemoveCurrent(DLinkedList *dlinked_list)
{
    if (dlinked_list->current == NULL)
        return false;
    DLinkedListNode *node = dlinked_list->current;
    if (node->previous != NULL)
        node->previous->next = node->next;
    else
        dlinked_list->first = NULL;
    if (node->next != NULL)
        node->next->previous = node->previous;
    else
        dlinked_list->last = NULL;
    free(node);
    dlinked_list->size--;
    dlinked_list->current = NULL;
    return true;
}

void dlinkedList_itrBegin(DLinkedList *dlinked_list)
{
    dlinked_list->current = dlinked_list->first;
}

void dlinkedList_itrNext(DLinkedList *dlinked_list)
{
    if (dlinked_list->current == NULL)
        return;
    dlinked_list->current = dlinked_list->current->next;
}

bool dlinkedList_itrEnd(DLinkedList *dlinked_list)
{
    return (dlinked_list->current == NULL) ? true : false;
}

void *dlinkedList_itrGet(DLinkedList *dlinked_list)
{
    return (dlinked_list->current == NULL) ? NULL : dlinked_list->current->addr;
}

int dlinkedList_size(DLinkedList *dlinked_list)
{
    return dlinked_list->size;
}

bool dlinkedList_empty(DLinkedList *dlinked_list)
{
    return (dlinked_list->first == NULL) ? true : false;
}

void dlinkedList_destroy(DLinkedList *dlinked_list)
{
    DLinkedListNode *node;
    while (dlinked_list->first != NULL)
    {
        node = dlinked_list->first;
        dlinked_list->first = dlinked_list->first->next;
        free(node);
    }
    free(dlinked_list);
}