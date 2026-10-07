#include <stdio.h>
#include "heap.h"

int main()
{
	heap_t h;
	init_heap(&h);
	
	int a[] = { -1, 20, 10, 40, 25, 60, 90, 70, 5 };
	int n = 8;
	build_heap(&h, a, n);
	disp_heap(&h);
	deinit_heap(&h);
	
}