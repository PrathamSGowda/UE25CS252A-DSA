#include <stdio.h>
#include "job.h"

int main()
{
	job_t job;
	set_job(&job, 1, 10);
	disp_job(&job);
	printf("priority : %d\n", get_priority(&job));
}