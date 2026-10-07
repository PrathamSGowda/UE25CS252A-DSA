#ifndef HEAP_H 
#define HEAP_H
#include "job.h"
#define MAXSIZE 100
struct heap 
{
	job_t key_[MAXSIZE];
	int n_;
};
typedef struct heap heap_t;

void init_heap(heap_t *ptr_heap);
void deinit_heap(heap_t *ptr_heap);
void insert_heap(heap_t *ptr_heap, job_t key);
job_t remove_max_heap(heap_t *ptr_heap);
void disp_heap(heap_t *ptr_heap);

int is_empty_heap(heap_t *ptr_heap);
int is_full_heap(heap_t *ptr_heap);
#endif