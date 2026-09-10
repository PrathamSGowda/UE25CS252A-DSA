#ifndef STACK_H
#define STACK_H
#include "dll.h"
// embed double ended queue in the stack 
// embedding | layering | containment | composition
struct stack 
{
	dll_t list_;
};
typedef struct stack stack_t;
void push(stack_t *ptr_stack, int key);
int pop(stack_t *ptr_stack);
int is_full_stack(stack_t *ptr_stack);
int is_empty_stack(stack_t *ptr_stack);

void init_stack(stack_t *ptr_stack);


#endif 
