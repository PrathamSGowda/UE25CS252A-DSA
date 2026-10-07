#ifndef HEAP_H 
#define HEAP_H
/*
heap :
	is a binary tree 
	not a binary search tree 
	has two properties 
	1. shape property 
	is a complete binary tree 
	has all nodes at higher level full 
	leftmost nodes at the lowest full 
	2. parental dominance 
	maxheap : parent key higher than that of the children recursively 
	minheap : parent key lower than that of the children recursively 
	
	Always implemented as an array 
	
*/
#define MAXSIZE 100
struct heap 
{
	int key_[MAXSIZE];
	int n_;
};
typedef struct heap heap_t;

void init_heap(heap_t *ptr_heap);
void deinit_heap(heap_t *ptr_heap);
void build_heap(heap_t *ptr_heap, int key[], int n);
void disp_heap(heap_t *ptr_heap);
#endif