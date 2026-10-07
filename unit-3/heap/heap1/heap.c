#include <stdio.h>
#include "heap.h"

void init_heap(heap_t *ptr_heap)
{
	ptr_heap->n_ = 0;
}

void deinit_heap(heap_t *ptr_heap)
{
	ptr_heap->n_ = 0;
}

void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}
void heapify(int key[], int n, int pos)
{
	int i = pos;
	int j = 2 * i;
	int is_heap = 0;
	while(! is_heap && j <= n)
	{
		if(j+1 <= n && key[j+1] > key[j])
		{
			++j;
		}
		if(key[j] > key[i])
		{
			swap(&key[j], &key[i]); 
			i = j;
			j = 2 * i;
		}
		else 
		{
			is_heap = 1;
		}
	}
}

void build_heap(heap_t *ptr_heap, int key[], int n)
{
	// copy the given array
	ptr_heap->n_ = n;
	for(int i = 1; i <= n; ++i)
	{
		ptr_heap->key_[i] = key[i];
	}
	// heapify the subtrees starting from the last internal node 
	for(int i = n/2; i >= 1; --i)
	{
		heapify(ptr_heap->key_, ptr_heap->n_, i);
	}
}

void disp_heap(heap_t *ptr_heap)
{
	for(int i = 1; i <= ptr_heap->n_; ++i)
	{
		printf("%d ", ptr_heap->key_[i]);
	}
	printf("\n");
}