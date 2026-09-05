#ifndef QUEUE_H
#define QUEUE_H
// array based implementation
// queue made using a circular list made using an array

#define MAXSIZE 5
struct queue
{
	int key_[MAXSIZE];
	// indices
	int front_;
	int rear_;
};
typedef struct queue queue_t;

void init(queue_t *ptr_queue);
void deinit(queue_t *ptr_queue);
void enqueue(queue_t *ptr_queue, int key);
int dequeue(queue_t *ptr_queue);

int is_empty(queue_t *ptr_queue);
int is_full(queue_t *ptr_queue);

#endif