#include <stdio.h>
#include "job.h"

void set_job(job_t *ptr_job, int job_no, int depth, int traffic)
{
    ptr_job->job_no_ = job_no;
    ptr_job->depth_ = depth;
    ptr_job->traffic_ = traffic;
}

void disp_job(job_t *ptr_job)
{
    printf("job # : %d depth : %d traffic : %d priority : %d\n",
           ptr_job->job_no_,
           ptr_job->depth_,
           ptr_job->traffic_,
           get_priority(ptr_job));
}

int get_priority(job_t *ptr_job)
{
    return ptr_job->depth_ + ptr_job->traffic_;
}
