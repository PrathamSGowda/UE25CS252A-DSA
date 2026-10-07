#include <stdio.h>
#include <stdlib.h>
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

void disp_heap(heap_t *ptr_heap)
{
	for(int i = 1; i <= ptr_heap->n_; ++i)
	{
		printf("%d ", ptr_heap->key_[i]);
	}
	printf("\n");
}

void insert_heap(heap_t *ptr_heap, int key)
{
	if(is_full_heap(ptr_heap))
	{
		printf("heap full\n"); exit(1);
	}
	ptr_heap->key_[++ptr_heap->n_] = key;
	int i = ptr_heap->n_;
	while(i > 1 && ptr_heap->key_[i] > ptr_heap->key_[i/2])
	{
		swap(&ptr_heap->key_[i], &ptr_heap->key_[i/2]);
		i = i / 2;
	}
}

int remove_max_heap(heap_t *ptr_heap)
{
	if(is_empty_heap(ptr_heap))
	{
		printf("heap empty\n"); exit(1);
	}
	int res = ptr_heap->key_[1];
	ptr_heap->key_[1] = ptr_heap->key_[ptr_heap->n_--];
	heapify(ptr_heap->key_, ptr_heap->n_, 1);
	return res;
}

int is_empty_heap(heap_t *ptr_heap)
{
	return ptr_heap->n_ == 0;
}

int is_full_heap(heap_t *ptr_heap)
{
	return ptr_heap->n_ == MAXSIZE - 1;
}

