#include <stdio.h>
#include "stack.h"

void init_stack(stack_t *ptr_stack)
{
    ptr_stack->top_ = -1;
}

void deinit_stack(stack_t *ptr_stack)
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
    if(! is_full(ptr_stack))
    {
        ptr_stack->key_[++ptr_stack->top_] = i;
    }
    else
    {
        printf("stack is full\n");
    }
}

int pop(stack_t *ptr_stack)
{
    if(! is_empty(ptr_stack))
    {
        return ptr_stack->key_[ptr_stack->top_--];
    }
    else
    {
        printf("stack is empty\n");
        return 0;
    }
}

int peek(stack_t *ptr_stack)
{
    if(! is_empty(ptr_stack))
    {
        return ptr_stack->key_[ptr_stack->top_];
    }
    else
    {
        printf("stack is empty\n");
        return 0;
    }
}