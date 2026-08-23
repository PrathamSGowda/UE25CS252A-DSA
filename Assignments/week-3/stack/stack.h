#ifndef STACK_H
#define STACK_H

#define MAX 100

struct stack
{
    int i_[MAX];
    int top_;
};
typedef struct stack stack_t;


void init_stack(stack_t *ptr_stack);
int is_empty(stack_t *ptr_stack);
int is_full(stack_t *ptr_stack);
void push(stack_t *ptr_stack, int i);
int pop(stack_t *ptr_stack);
void disp(stack_t *ptr_stack);

// assuming i starts from 1
int get_ith_element(stack_t *ptr_stack, int i);
int set_ith_element(stack_t *ptr_stack, int i, int val);

#endif