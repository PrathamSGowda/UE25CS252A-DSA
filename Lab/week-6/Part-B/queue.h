#ifndef QUEUE_H
#define QUEUE_H

#include "dll.h"

struct queue
{
    dll_t list_;
};

typedef struct queue queue_t;

void enqueue(queue_t *ptr_queue, int key);
int dequeue(queue_t *ptr_queue);

int is_empty_queue(queue_t *ptr_queue);
int is_full_queue(queue_t *ptr_queue);

void display_queue(queue_t *ptr_queue);
void init_queue(queue_t *ptr_queue);

#endif