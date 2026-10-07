#include <stdio.h>
#include "heap.h"

int main()
{
	heap_t h;
	init_heap(&h);
	int key;
	int opt;
	printf("1 : add; 2 : remove max; 3 : disp; 0 : exit : ");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : scanf("%d", &key); insert_heap(&h, key); break; 
			case 2 : key = remove_max_heap(&h); printf("max : %d\n", key); break;
			case 3 : disp_heap(&h); break;
		}
		printf("1 : add; 2 : remove max; 3 : disp; 0 : exit : ");
		scanf("%d", &opt);
	}
	deinit_heap(&h);
	
}