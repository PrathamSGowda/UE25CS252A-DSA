#include <stdio.h>
#include "priority_queue.h" 

int main()
{
	priority_queue_t q;
	init(&q);
	
	job_t job;
	int priority;
	int job_no = 1;
	
	int opt;
	printf("enter 1. enqueue 2. dequeue 0. exit : ");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : printf("enter priority : ");
					 scanf("%d", &priority);
					 set_job(&job, job_no++, priority);
					 enqueue(&q, job);
					 break;
					 
			case 2 : job = dequeue(&q);
					 disp_job(&job);
					 break;
			
		}
		printf("enter 1. enqueue 2. dequeue 0. exit : ");
		scanf("%d", &opt);
	}
	
	deinit(&q);
}