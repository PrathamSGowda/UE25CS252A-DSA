#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



void init_stack(stack_t *ptr_stack)
{
	ptr_stack->top_ = -1;
}
void deinit_stack(stack_t *ptr_stack)
{
	// TODO
	// deinit each tree
	// reset stack
}
void push(stack_t *ptr_stack, char ch)
{
	if(is_full(ptr_stack))
	{
		printf("stack full; cannot push\n");
	}
	else if(ch >= '0' && ch <= '9')
	{
		node_t* temp = (node_t*)malloc(sizeof(node_t));
		temp->ch_ = ch;
		temp->left_ = temp->right_ = NULL;
		ptr_stack->ch_[++ptr_stack->top_] = temp;
	}
	else 
	{
		node_t* temp = (node_t*)malloc(sizeof(node_t));
		temp->ch_ = ch;
		temp->right_ = pop(ptr_stack);
		temp->left_ = pop(ptr_stack);
		ptr_stack->ch_[++ptr_stack->top_] = temp;

	}
}
node_t* pop(stack_t *ptr_stack)
{
	if(is_empty(ptr_stack))
	{
		printf("stack empty; cannot pop\n");
		exit(1);
	}
	else
	{
		return ptr_stack->ch_[ptr_stack->top_--];
	}
}
node_t* peek(stack_t *ptr_stack)
{
	if(is_empty(ptr_stack))
	{
		printf("stack empty; cannot pop\n");
		exit(1);
	}
	else
	{
		return ptr_stack->ch_[ptr_stack->top_];
	}
}

int is_empty(stack_t *ptr_stack)
{
	return ptr_stack->top_ == -1;
}
int is_full(stack_t *ptr_stack)
{
	return ptr_stack->top_ + 1 == MAX;
}
int eval(node_t* temp)
{
	// check for operand => leaf 
	if(temp->left_ == NULL && temp->right_ == NULL)
	{
		return temp->ch_ - '0';
	}
	else // take care of operators and subtrees 
	{
		int left = eval(temp->left_);
		int right = eval(temp->right_);
		switch(temp->ch_)
		{
			case '*' : return left * right; break;
			case '/' : return left / right; break;
			case '+' : return left + right; break;
			case '-' : return left - right; break;
		}
		return 0;
	}
}