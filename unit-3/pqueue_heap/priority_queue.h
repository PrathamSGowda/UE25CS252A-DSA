#ifndef PRIOROTY_QUEUE_H 
#define PRIOROTY_QUEUE_H 

#include "heap.h"

struct priority_queue 
{
	heap_t h_;
};
typedef struct priority_queue priority_queue_t;

void init(priority_queue_t *ptr_pqueue);
void deinit(priority_queue_t *ptr_pqueue);

void enqueue(priority_queue_t *ptr_pqueue, job_t job);
job_t dequeue(priority_queue_t *ptr_pqueue);

int is_full(priority_queue_t *ptr_pqueue);
int is_empty(priority_queue_t *ptr_pqueue);


#endif