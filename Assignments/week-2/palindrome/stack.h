#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct stack
{
    char ch_[MAX];
    int top_;
}stack_t;

void init_stack(stack_t *ptr_stack);
int is_empty(stack_t *ptr_stack);
int is_full(stack_t *ptr_stack);
void push(stack_t *ptr_stack, char ch);
char pop(stack_t *ptr_stack);

#endif