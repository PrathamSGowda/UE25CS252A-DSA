#ifndef JOB_H
#define JOB_H

struct job
{
    int job_no_;
    int depth_;
    int traffic_;
};

typedef struct job job_t;

void set_job(job_t *ptr_job, int job_no, int depth, int traffic);
void disp_job(job_t *ptr_job);
int get_priority(job_t *ptr_job);

#endif
