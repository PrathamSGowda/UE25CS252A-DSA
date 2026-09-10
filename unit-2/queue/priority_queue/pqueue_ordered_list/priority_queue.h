#ifndef PRIOROTY_QUEUE_H 
#define PRIOROTY_QUEUE_H 
// priority queue :
//	supports two operations 
//	1. enqueue : add a job with some priority to the queue 
//	2. dequeue : remove the job with the highest priority 

// possible implementations 
// 1. unordered list 
// 2. ordered list 
// 3. unordered array 
// 4. ordered array 

// 5. heap 
#include "job.h"

struct node
{
	job_t job_;
	struct node *next_;
};
typedef struct node node_t;

struct priority_queue 
{
	node_t* front_;
	node_t* rear_;
};
typedef struct priority_queue priority_queue_t;

void init(priority_queue_t *ptr_pqueue);
void deinit(priority_queue_t *ptr_pqueue);

void enqueue(priority_queue_t *ptr_pqueue, job_t job);
job_t dequeue(priority_queue_t *ptr_pqueue);

int is_full(priority_queue_t *ptr_pqueue);
int is_empty(priority_queue_t *ptr_pqueue);


#endif