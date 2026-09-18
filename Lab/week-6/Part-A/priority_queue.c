#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

void init(priority_queue_t *ptr_pqueue)
{
    ptr_pqueue->front_ = NULL;
}

void deinit(priority_queue_t *ptr_pqueue)
{
    node_t *pres = ptr_pqueue->front_;
    node_t *temp;

    while(pres)
    {
        temp = pres;
        pres = pres->next_;
        free(temp);
    }

    ptr_pqueue->front_ = NULL;
}

void enqueue(priority_queue_t *ptr_pqueue, job_t job)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));

    if(temp == NULL)
    {
        printf("queue full\n");
        exit(1);
    }

    temp->job_ = job;
    temp->next_ = NULL;

    if(is_empty(ptr_pqueue) ||
       get_priority(&job) > get_priority(&ptr_pqueue->front_->job_))
    {
        temp->next_ = ptr_pqueue->front_;
        ptr_pqueue->front_ = temp;
        return;
    }

    node_t *pres = ptr_pqueue->front_;

    while(pres->next_ != NULL &&
          get_priority(&pres->next_->job_) >= get_priority(&job))
    {
        pres = pres->next_;
    }

    temp->next_ = pres->next_;
    pres->next_ = temp;
}

job_t dequeue(priority_queue_t *ptr_pqueue)
{
    if(is_empty(ptr_pqueue))
    {
        printf("empty queue\n");
        exit(1);
    }

    node_t *temp = ptr_pqueue->front_;
    job_t job = temp->job_;

    ptr_pqueue->front_ = temp->next_;

    free(temp);
    return job;
}

int is_full(priority_queue_t *ptr_pqueue)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    free(temp);
    return temp == NULL;
}

int is_empty(priority_queue_t *ptr_pqueue)
{
    return ptr_pqueue->front_ == NULL;
}
