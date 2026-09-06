#ifndef PRIOROTY_QUEUE_H 
#define PRIOROTY_QUEUE_H 

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

void block(priority_queue_t *ptr_pqueue, int job_no);
void unblock(priority_queue_t *ptr_pqueue, int job_no);

void init(priority_queue_t *ptr_pqueue);
void deinit(priority_queue_t *ptr_pqueue);

void enqueue(priority_queue_t *ptr_pqueue, job_t job);
job_t dequeue(priority_queue_t *ptr_pqueue);

int is_full(priority_queue_t *ptr_pqueue);
int is_empty(priority_queue_t *ptr_pqueue);


#endif