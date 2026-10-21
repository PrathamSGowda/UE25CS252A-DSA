#ifndef QUEUE_H
#define QUEUE_H
// list based implementation
// to make enqueue and dequeue require a few operations,
//	next field should run from the front towards the rear
struct node 
{
	int key_;
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
void enqueue(queue_t *ptr_queue, int key);
int dequeue(queue_t *ptr_queue);

int is_empty(queue_t *ptr_queue);
int is_full(queue_t *ptr_queue);

#endif