#include <stdio.h>
#include "stack.h"

void push(stack_t *ptr_stack, int key)
{
	add_at_end(&ptr_stack->list_, key);
}
int pop(stack_t *ptr_stack)
{
	return remove_at_end(&ptr_stack->list_);
}
int is_full_stack(stack_t *ptr_stack)
{
	return is_full(&ptr_stack->list_);
}
int is_empty_stack(stack_t *ptr_stack)
{
	return is_empty(&ptr_stack->list_);
}

void init_stack(stack_t *ptr_stack)
{
	init(&ptr_stack->list_);
}