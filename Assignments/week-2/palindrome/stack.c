#include <stdio.h>
#include "stack.h"

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

void push(stack_t *ptr_stack, char ch)
{
    if(is_full(ptr_stack))
        printf("Stack is full\n");
    else
        ptr_stack->ch_[++ptr_stack->top_] = ch;
}

char pop(stack_t *ptr_stack)
{
    if(is_empty(ptr_stack))
        printf("Stack is empty\n");
    else
        return ptr_stack->ch_[ptr_stack->top_--];
}

