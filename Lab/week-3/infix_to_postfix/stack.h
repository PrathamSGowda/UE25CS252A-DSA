#ifndef STACK_H
#define STACK_H

#define MAX 100
typedef struct stack
{
    int key_[MAX];
    int top_;
}stack_t;

void init_stack(stack_t *ptr_stack);
void deinit_stack(stack_t *ptr_stack);
void push(stack_t *ptr_stack, int ch);
int pop(stack_t *ptr_stack);
int peek(stack_t *ptr_stack);
int is_empty(stack_t *ptr_stack);
int is_full(stack_t *ptr_stack);

#endif