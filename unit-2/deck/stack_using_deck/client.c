#include <stdio.h>
#include "stack.h"

int main()
{
	stack_t mystack;
	init_stack(&mystack);
	int s[] = {10, 20, 30, 40}; 
	int n = 4;
	for(int i = 0; i < n; ++i)
	{	
		push(&mystack, s[i]);
	}
	printf("removing ...\n");
	while(! is_empty_stack(&mystack))
	{
		printf("%d ", pop(&mystack));
	}
	printf("\n");
	
}