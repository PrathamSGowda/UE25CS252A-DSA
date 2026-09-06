#include <stdio.h>
#include "job.h"

void set_job(job_t *ptr_job, int job_no)
{
	ptr_job->job_no_ = job_no;
	ptr_job->priority_ = 999;
}

void disp_job(job_t *ptr_job)
{
	printf("job # : %d\n", 	ptr_job->job_no_);
}

int get_priority(job_t *ptr_job)
{
	return ptr_job->priority_;
}