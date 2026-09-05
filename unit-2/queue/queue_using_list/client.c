#include <stdio.h>
#include "queue.h"

int main()
{
	queue_t q;
	init(&q);
	
	int key;
	
	int opt;
	printf("1. enqueue 2. dequeue 0. exit : ");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : scanf("%d", &key); enqueue(&q, key); break;
			case 2 : key = dequeue(&q); printf("%d\n", key); break;
		}
		printf("1. enqueue 2. dequeue 0. exit : ");
		scanf("%d", &opt);
	}
	
	deinit(&q);
}