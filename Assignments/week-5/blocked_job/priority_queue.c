#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

void block(priority_queue_t *ptr_pqueue, int job_no)
{
	node_t *pres = ptr_pqueue->front_;

	while(pres)
	{
		if(pres->job_.job_no_ == job_no)
		{
			pres->job_.priority_ = 0;
			return;
		}
		pres = pres->next_;
	}
	printf("job id not found");
}

void unblock(priority_queue_t *ptr_pqueue, int job_no)
{
	node_t *pres = ptr_pqueue->front_;

	while(pres)
	{
		if(pres->job_.job_no_ == job_no)
		{
			if(pres->job_.priority_ == 0)
			{
				pres->job_.priority_ = 999;
			}
			else
			{
				printf("job was never blocked\n");
			}
			return;
		}
		pres = pres->next_;
	}
	printf("job id not found");
}

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
	temp->job_ = job;
	
	if(temp == NULL)
	{
		printf("queue full\n"); exit(1);
	}
	temp->next_ = NULL;
	if(is_empty(ptr_pqueue))
	{
		ptr_pqueue->front_ = temp;
	}
	else 
	{
		ptr_pqueue->rear_->next_ = temp;
	}
	ptr_pqueue->rear_ = temp;
}

job_t dequeue(priority_queue_t *ptr_pqueue)
{
	// case 1 : empty list 
	if(is_empty(ptr_pqueue))
	{
		printf("empty queue\n"); exit(1);
	}
	int max_priority = 0;
	node_t* max_pres = NULL;
	node_t* max_prev = NULL;
	node_t* prev = NULL;
	node_t* pres = ptr_pqueue->front_;
	while(pres != NULL)
	{
		if(get_priority(&pres->job_) > max_priority)
		{
			max_priority = get_priority(&pres->job_);
			max_prev = prev;
			max_pres = pres;
		}
		prev = pres;
		pres = pres->next_;
	}
	// add modification to data structure
	// case 2 : single node 
	if(ptr_pqueue->front_ == ptr_pqueue->rear_)
	{
		ptr_pqueue->front_ = ptr_pqueue->rear_ = NULL;
	}
	// case 3 : remove in the front 
	else if(ptr_pqueue->front_ == max_pres)
	{
		ptr_pqueue->front_ = max_pres->next_;
	}
	// case 4 : remove the last node
	else if(ptr_pqueue->rear_ == max_pres)
	{
		max_prev->next_ = NULL;
		ptr_pqueue->rear_ = max_prev;
	}
	// case 5 : any # of nodes 
	else 
	{
		max_prev->next_ = max_pres->next_;
	}
	
	job_t job = max_pres->job_;
	free(max_pres);
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