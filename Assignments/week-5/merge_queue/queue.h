#ifndef QUEUE_H
#define QUEUE_H

struct node 
{
	int key_;
	int AT_; // arrival time
	struct node* next_;
};
typedef struct node node_t;

struct queue
{
	node_t* front_;
	node_t* rear_;
};
typedef struct queue queue_t;

void init(queue_t *ptr_queue);
void deinit(queue_t *ptr_queue);
void enqueue(queue_t *ptr_queue, int key, int AT);
int dequeue(queue_t *ptr_queue);

int is_empty(queue_t *ptr_queue);
int is_full(queue_t *ptr_queue);

void merge_queues(queue_t *ptr_queue1, queue_t *ptr_queue2, queue_t *ptr_queue3);

#endif