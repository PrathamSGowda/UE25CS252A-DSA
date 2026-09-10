#ifndef PRIOROTY_QUEUE_H 
#define PRIOROTY_QUEUE_H 

#include "job.h"
#define MAXSIZE 100
struct priority_queue 
{
	job_t job_[MAXSIZE];
	int n_; // size 
};
typedef struct priority_queue priority_queue_t;

void init(priority_queue_t *ptr_pqueue);
void deinit(priority_queue_t *ptr_pqueue);

void enqueue(priority_queue_t *ptr_pqueue, job_t job);
job_t dequeue(priority_queue_t *ptr_pqueue);

int is_full(priority_queue_t *ptr_pqueue);
int is_empty(priority_queue_t *ptr_pqueue);


#endif