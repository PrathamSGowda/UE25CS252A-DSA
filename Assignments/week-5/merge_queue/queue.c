#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void merge_queues(queue_t *ptr_queue1, queue_t *ptr_queue2, queue_t *ptr_queue3)
{
	node_t *pres1 = ptr_queue1->front_;
	node_t *pres2 = ptr_queue2->front_;

	while(pres1 && pres2)
	{
		if(pres1->AT_ == pres2->AT_) // giving q1 priority over q2 incase of same AT
		{
			enqueue(ptr_queue3, pres1->key_, pres1->AT_);
			enqueue(ptr_queue3, pres2->key_, pres2->AT_);

			pres1 = pres1->next_;
			pres2 = pres2->next_;
		}
		else if(pres1->AT_ < pres2->AT_)
		{
			enqueue(ptr_queue3, pres1->key_, pres1->AT_);
			pres1 = pres1->next_;
		}
		else
		{
			enqueue(ptr_queue3, pres2->key_, pres2->AT_);
			pres2 = pres2->next_;
		}
	}
	// to handle unequal queue size
	while(pres1)
	{
		enqueue(ptr_queue3, pres1->key_, pres1->AT_);
		pres1 = pres1->next_;
	}
	while(pres2)
	{
		enqueue(ptr_queue3, pres2->key_, pres2->AT_);
		pres2 = pres2->next_;
	}
} // merge logic is similar to add logic in polynomial

void init(queue_t *ptr_queue)
{
	ptr_queue->front_ = ptr_queue->rear_ = NULL;
}

void deinit(queue_t *ptr_queue)
{
	while(! is_empty(ptr_queue))
	{
		dequeue(ptr_queue);
	}
}

static node_t* create_node(int key, int AT)
{
	node_t* temp = (node_t*) malloc(sizeof(node_t));
	if(temp == NULL)
	{
		printf("queue full\n");
		exit(1);
	}
	temp->key_ = key;
	temp->AT_ = AT;
	return temp;
}

void enqueue(queue_t *ptr_queue, int key, int AT)
{
	node_t* temp = create_node(key,AT);
	temp->next_ = NULL;
	if(is_empty(ptr_queue))
	{
		ptr_queue->front_ = temp;
	}
	else 
	{
		ptr_queue->rear_->next_ = temp;
	}
	ptr_queue->rear_ = temp;
}


int dequeue(queue_t *ptr_queue)
{
	if(is_empty(ptr_queue))
	{
		printf("queue empty\n"); exit(1);
	}
	node_t *temp = ptr_queue->front_;
	int key = temp->key_;
	
	ptr_queue->front_ = temp->next_;
	if(ptr_queue->front_ == NULL)
	{
		ptr_queue->rear_ = NULL;
	}
	free(temp);
	return key;
}

int is_empty(queue_t *ptr_queue)
{
	return ptr_queue->front_ == NULL;
}
int is_full(queue_t *ptr_queue)
{
	// test whether malloc succeeds 
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	free(temp);
	return temp == NULL;
}

