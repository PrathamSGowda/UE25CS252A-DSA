#include <stdio.h>
#include "queue.h"

int main()
{
	queue_t q1;
	init(&q1);

	queue_t q2;
	init(&q2);

	queue_t q3;
	init(&q3);
	
	int key;
	int AT;

	int opt;
	printf("1. enqueue in q1; 2. enqueue in q2; 3. merge q1 and q2; 4. dequeue in merged queue; 0. exit : ");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : printf("Enter key and time : "); scanf("%d %d",&key,&AT); enqueue(&q1,key,AT); break;
			case 2 : printf("Enter key and time : "); scanf("%d %d",&key,&AT); enqueue(&q2,key,AT); break;
			case 3 : merge_queues(&q1,&q2,&q3); break;
			case 4 : key = dequeue(&q3); printf("%d\n", key); break;
		}
		printf("1. enqueue in q1; 2. enqueue in q2; 3. merge q1 and q2; 4. dequeue in merged queue; 0. exit : ");
		scanf("%d", &opt);
	}
	
	deinit(&q1);
	deinit(&q2);
	deinit(&q3);
}