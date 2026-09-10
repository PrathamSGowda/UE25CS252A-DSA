#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

void init(priority_queue_t *ptr_pqueue)
{
	ptr_pqueue->front_ = ptr_pqueue->rear_ = NULL;
}

void deinit(priority_queue_t *ptr_pqueue)
{
	node_t* pres = ptr_pqueue->front_;
	node_t* temp;
	while(pres)
	{
		temp = pres;
		pres = pres->next_;
		free(temp);
	}
	ptr_pqueue->front_ = ptr_pqueue->rear_ = NULL;
}


void enqueue(priority_queue_t *ptr_pqueue, job_t job)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	if(temp == NULL)
	{
		printf("queue full\n"); exit(1);
	}
	temp->job_ = job; temp->next_ = NULL;
	
	// empty 
	if(is_empty(ptr_pqueue))
	{
		ptr_pqueue->front_ = ptr_pqueue->rear_ = temp;
	}
	else 
	{
		node_t* prev = NULL;
		node_t* pres = ptr_pqueue->front_;
		// find the pos to insert
		while(pres != NULL &&
			get_priority(&pres->job_) >= get_priority(&job))
		{
			prev = pres;
			pres = pres->next_;
		}
		// insert 
		// beginning
		if(prev == NULL)
		{
			temp->next_ = pres;
			ptr_pqueue->front_ = temp;
		}
		// end 
		else if(pres == NULL)
		{
			prev->next_ = temp;
			ptr_pqueue->rear_ = temp;
		}
		// middle
		else
		{
			prev->next_ = temp;
			temp->next_ = pres;
		}
		
	}
	
	
	
	

}
job_t dequeue(priority_queue_t *ptr_pqueue)
{
	if(is_empty(ptr_pqueue))
	{
		printf("empty queue\n"); exit(1);
	}
	node_t* temp = ptr_pqueue->front_;
	job_t job = temp->job_;
	
	ptr_pqueue->front_ = temp->next_;
	if(ptr_pqueue->front_ == NULL) // one node case
	{
		ptr_pqueue->rear_ = NULL;
	}
	
	free(temp);
	return job;

}

int is_full(priority_queue_t *ptr_pqueue)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	free(temp);
	return temp == NULL;
}

int is_empty(priority_queue_t *ptr_pqueue)
{
	return ptr_pqueue->front_ == NULL;
}