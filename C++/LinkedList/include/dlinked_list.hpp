#ifndef DLINKED_LIST_HPP
#define DLINKED_LIST_HPP

class DLinkedList
{
private:
  typedef struct node
  {
    void *addr;
    struct node *previous;
    struct node *next;
  } LL_Node;
  LL_Node *first;
  LL_Node *current;
  LL_Node *last;
  int size;

public:
  DLinkedList();
  virtual ~DLinkedList();
  bool addFirst(void *addr);
  bool addLast(void *addr);
  bool add(void *addr, int index);
  void *removeFirst();
  void *removeLast();
  void *remove(int index);
  void *get(int index);
  int getSize();
  bool empty();
  void itrBegin();
  bool itrEnd();
  void itrNext();
  void *itrGet();
  bool itrAdd(void *addr);
  bool itrRemove();
};

#endif