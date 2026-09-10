#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

void init(priority_queue_t *ptr_pqueue)
{
	ptr_pqueue->n_ = 0;
}

void deinit(priority_queue_t *ptr_pqueue)
{
	// no resources
	ptr_pqueue->n_ = 0;	
}


void enqueue(priority_queue_t *ptr_pqueue, job_t job)
{
	if(is_full(ptr_pqueue))
	{
		printf("full\n"); exit(1);
	}
	int i = ptr_pqueue->n_ - 1;
	while(i >= 0 && 
		get_priority(&ptr_pqueue->job_[i]) >= get_priority(&job))
	{
		ptr_pqueue->job_[i+1] = ptr_pqueue->job_[i];
		--i;
	}
	ptr_pqueue->job_[i+1] = job;
	++ptr_pqueue->n_;
}
job_t dequeue(priority_queue_t *ptr_pqueue)
{
	if(is_empty(ptr_pqueue))
	{
		printf("empty queue\n"); exit(1);
	}
	return ptr_pqueue->job_[--ptr_pqueue->n_];
}

int is_full(priority_queue_t *ptr_pqueue)
{
	return ptr_pqueue->n_ == MAXSIZE;
}

int is_empty(priority_queue_t *ptr_pqueue)
{
	return ptr_pqueue->n_ == 0;
}