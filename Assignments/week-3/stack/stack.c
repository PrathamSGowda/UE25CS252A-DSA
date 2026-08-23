#include <stdio.h>
#include "stack.h"

int set_ith_element(stack_t *ptr_stack, int i, int val)
{
    stack_t local;
    init_stack(&local);

    while(i>1)
    {
        push(&local, pop(ptr_stack));
        --i;        
    }

    int prev_val = pop(ptr_stack);
    push(ptr_stack,val);

    while(! is_empty(&local))
    {
        push(ptr_stack, pop(&local));
    }

    return prev_val;
}

int get_ith_element(stack_t *ptr_stack, int i)
{
    stack_t local;
    init_stack(&local);

    while(i>1)
    {
        push(&local, pop(ptr_stack));
        --i;
    }

    int val = pop(ptr_stack);

    while(! is_empty(&local))
    {
        push(ptr_stack, pop(&local));
    }

    return val;
}

void init_stack(stack_t *ptr_stack)
{
    ptr_stack->top_ = -1;
}

int is_empty(stack_t *ptr_stack)
{
	return ptr_stack->top_ == -1;
}
int is_full(stack_t *ptr_stack)
{
	return ptr_stack->top_ + 1 == MAX;
}

void push(stack_t *ptr_stack, int i)
{
    if(is_full(ptr_stack))
        printf("Stack is full\n");
    else
        ptr_stack->i_[++ptr_stack->top_] = i;
}

int pop(stack_t *ptr_stack)
{
    if(is_empty(ptr_stack))
        printf("Stack is empty\n");
    else
        return ptr_stack->i_[ptr_stack->top_--];
}

void disp(stack_t *ptr_stack)
{
    int i = ptr_stack->top_;
    while (i >= 0)
    {
        printf("%d ", ptr_stack->i_[i]);
        i--;
    }
    printf("\n");
}