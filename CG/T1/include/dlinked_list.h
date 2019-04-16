#ifndef DLINKED_LIST_H
#define DLINKED_LIST_H

#include <stdbool.h>

typedef struct dlinked_list DLinkedList;

DLinkedList *linkedList_create();
void dlinkedList_destroy(DLinkedList *dlinked_list);
bool dlinkedList_empty(DLinkedList *dlinked_list);
int dlinkedList_size(DLinkedList *dlinked_list);
void dlinkedList_insertFirst(DLinkedList *dlinked_list, void *addr);
void dlinkedList_insertLast(DLinkedList *dlinked_list, void *addr);
void *dlinkedList_removeFirst(DLinkedList *dlinked_list);
void *dlinkedList_removeLast(DLinkedList *dlinked_list);
void dlinkedList_itrBegin(DLinkedList *dlinked_list);
bool dlinkedList_itrEnd(DLinkedList *dlinked_list);
void dlinkedList_itrNext(DLinkedList *dlinked_list);
void *dlinkedList_itrGet(DLinkedList *dlinked_list);
bool dlinkedList_itrInsertCurrent(DLinkedList *dlinked_list, void *addr);
bool dlinkedList_itrRemoveCurrent(DLinkedList *dlinked_list);

#endif /* DLINKED_LIST_H */