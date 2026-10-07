#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

void init(priority_queue_t *ptr_pqueue)
{
	init_heap(&ptr_pqueue->h_);
}

void deinit(priority_queue_t *ptr_pqueue)
{
	deinit_heap(&ptr_pqueue->h_);	
}


void enqueue(priority_queue_t *ptr_pqueue, job_t job)
{
	insert_heap(&ptr_pqueue->h_, job);
}
job_t dequeue(priority_queue_t *ptr_pqueue)
{

	return remove_max_heap(&ptr_pqueue->h_);
}

int is_full(priority_queue_t *ptr_pqueue)
{
	return is_full_heap(&ptr_pqueue->h_);
}

int is_empty(priority_queue_t *ptr_pqueue)
{
	return is_empty_heap(&ptr_pqueue->h_);
}