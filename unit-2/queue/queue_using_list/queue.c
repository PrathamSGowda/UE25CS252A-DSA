#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


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

static node_t* create_node(int key)
{
	node_t* temp = (node_t*) malloc(sizeof(node_t));
	if(temp == NULL)
	{
		printf("queue full\n");
		exit(1);
	}
	temp->key_ = key;
	return temp;
}
// critical cases :
// 1, empty 
// 2. some nodes
void enqueue(queue_t *ptr_queue, int key)
{
	node_t* temp = create_node(key);
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

