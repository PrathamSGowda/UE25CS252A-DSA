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
	// add at the end 
	ptr_pqueue->job_[ptr_pqueue->n_++] = job;
}
job_t dequeue(priority_queue_t *ptr_pqueue)
{
	if(is_empty(ptr_pqueue))
	{
		printf("empty queue\n"); exit(1);
	}
	// find the pos of the max 
	int i;
	int max_priority = 0;
	int max_pos = 0;
	int temp_priority;
	for(i = 0; i < ptr_pqueue->n_; ++i)
	{
		if((temp_priority = get_priority(&ptr_pqueue->job_[i]))
			> max_priority)
		{
			max_priority = temp_priority;
			max_pos = i;
		}
	}
	job_t job = ptr_pqueue->job_[max_pos];
	
	// shift
	for(int i = max_pos + 1 ; i < ptr_pqueue->n_; ++i)
	{
		ptr_pqueue->job_[i-1] = ptr_pqueue->job_[i];
	}
	--ptr_pqueue->n_;
	
	return job;
}

int is_full(priority_queue_t *ptr_pqueue)
{
	return ptr_pqueue->n_ == MAXSIZE;
}

int is_empty(priority_queue_t *ptr_pqueue)
{
	return ptr_pqueue->n_ == 0;
}