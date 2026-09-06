#include <stdio.h>
#include "priority_queue.h" 

int main()
{
	priority_queue_t q;
	init(&q);
	
	job_t job;
	int priority;
	int job_no = 1;
	int no;

	int opt;
	printf("enter 1. enqueue; 2. dequeue; 3. block; 4. unblock; 0. exit : ");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : set_job(&job, job_no++); enqueue(&q, job); break;
			case 2 : job = dequeue(&q); disp_job(&job); break;
			case 3 : printf("enter job # to block : "); scanf("%d",&no); block(&q,no); break;
			case 4 : printf("enter job # to unblock : "); scanf("%d",&no); unblock(&q,no); break;
		}
		printf("enter 1. enqueue; 2. dequeue; 3. block; 4. unblock; 0. exit : ");
		scanf("%d", &opt);
	}
	
	deinit(&q);
}