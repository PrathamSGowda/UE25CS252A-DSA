#ifndef HEAP_H 
#define HEAP_H

#define MAXSIZE 100
struct heap 
{
	int key_[MAXSIZE];
	int n_;
};
typedef struct heap heap_t;

void init_heap(heap_t *ptr_heap);
void deinit_heap(heap_t *ptr_heap);
void insert_heap(heap_t *ptr_heap, int key);
int remove_max_heap(heap_t *ptr_heap);
void disp_heap(heap_t *ptr_heap);

int is_empty_heap(heap_t *ptr_heap);
int is_full_heap(heap_t *ptr_heap);
#endif