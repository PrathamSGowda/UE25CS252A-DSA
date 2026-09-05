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

// add at the rear 
// not consider the priority 
// diff cases :
// 
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
#if 0
// 1. walk through 
job_t dequeue(priority_queue_t *ptr_pqueue)
{
	node_t* pres = ptr_pqueue->front_;
	while(pres != NULL)
	{
		pres = pres->next_;
	}
}
#endif

#if 0
// 1. walk through 
// 2. find max priority
job_t dequeue(priority_queue_t *ptr_pqueue)
{
	int max_priority = 0;
	node_t* pres = ptr_pqueue->front_;
	while(pres != NULL)
	{
		if(get_priority(&pres->job_) > max_priority)
		{
			max_priority = get_priority(&pres->job_);
		}
		pres = pres->next_;
	}
}
#endif

#if 0
// 1. walk through 
// 2. find max priority
// 3. find the position
job_t dequeue(priority_queue_t *ptr_pqueue)
{
	int max_priority = 0;
	node_t* max_pres = NULL;
	node_t* pres = ptr_pqueue->front_;
	while(pres != NULL)
	{
		if(get_priority(&pres->job_) > max_priority)
		{
			max_priority = get_priority(&pres->job_);
			max_pres = pres;
		}
		pres = pres->next_;
	}
}
#endif

// 1. walk through 
// 2. find max priority
// 3. find the position
// 4. find the node previous to the max_pres
#if 0
job_t dequeue(priority_queue_t *ptr_pqueue)
{
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
}
#endif 

// 1. walk through 
// 2. find max priority
// 3. find the position
// 4. find the node previous to the max_pres
// 6. return the value
#if 0
job_t dequeue(priority_queue_t *ptr_pqueue)
{
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
	
	node_t job = max_pres->job_;
	free(max_pres);
	return job;
}
#endif 
// 1. walk through 
// 2. find max priority
// 3. find the position
// 4. find the node previous to the max_pres
// 5. modify the data stcture 
//		
// 6. return the value
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