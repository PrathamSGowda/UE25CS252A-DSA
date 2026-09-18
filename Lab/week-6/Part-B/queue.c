#include <stdio.h>
#include "queue.h"

void enqueue(queue_t *ptr_queue, int key)
{
    add_at_end(&ptr_queue->list_, key);
}

int dequeue(queue_t *ptr_queue)
{
    return remove_in_begin(&ptr_queue->list_);
}

int is_empty_queue(queue_t *ptr_queue)
{
    return is_empty(&ptr_queue->list_);
}

int is_full_queue(queue_t *ptr_queue)
{
    return is_full(&ptr_queue->list_);
}

void display_queue(queue_t *ptr_queue)
{
    disp_forward(&ptr_queue->list_);
}

void init_queue(queue_t *ptr_queue)
{
    init(&ptr_queue->list_);
}  