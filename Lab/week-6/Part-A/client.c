#include <stdio.h>
#include "priority_queue.h"

int main()
{
    priority_queue_t q;
    job_t job;

    int depth;
    int traffic;
    int job_no = 1;
    int opt;

    init(&q);

    printf("enter 1. enqueue 2. dequeue 0. exit : ");
    scanf("%d", &opt);

    while(opt)
    {
        switch(opt)
        {
            case 1:
                printf("enter pothole depth (1-5) : ");
                scanf("%d", &depth);
                printf("enter traffic heaviness (1-5) : ");
                scanf("%d", &traffic);
                set_job(&job, job_no++, depth, traffic);
                enqueue(&q, job);
                printf("job added with priority %d\n",
                       get_priority(&job));

                break;
            case 2:
                if(!is_empty(&q))
                {
                    job = dequeue(&q);

                    printf("processing ");
                    disp_job(&job);
                }
                else
                {
                    printf("queue is empty\n");
                }
                break;
            default:
                printf("invalid option\n");
        }
        printf("\nenter 1. enqueue 2. dequeue 0. exit : ");
        scanf("%d", &opt);
    }

    deinit(&q);
    return 0;
}