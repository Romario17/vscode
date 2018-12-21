#ifndef FIFO_H
#define FIFO_H

#include <stdbool.h>

typedef struct fifo Fifo;

Fifo *fifo_create();
bool fifo_enqueue(Fifo *fifo, void *addr);
bool fifo_dequeue(Fifo *fifo, void **receiver);
int fifo_size(Fifo *fifo);
void fifo_destroy(Fifo *fifo);

#endif /* FIFO_H */