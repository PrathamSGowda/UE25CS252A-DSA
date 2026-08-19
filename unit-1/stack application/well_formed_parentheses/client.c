#include <stdio.h>
#include "stack.h"

int is_balanced(char *s)
{
	stack_t mystack;
	init_stack(&mystack);
	
	char ch;
	int is_valid = 1;
	while(is_valid && (ch = *s++) != '\0')
	{
		if(ch == '(')
		{
			push(&mystack, 'x');
		}
		else if(ch == ')')
		{
			if(! is_empty(&mystack))
			{
				pop(&mystack);
			}
			else 
			{
				is_valid = 0;
			}
		}
	}
	int isEmpty = is_empty(&mystack);
	deinit_stack(&mystack);
	return is_valid && isEmpty;
}

// well formed parentheses
int main()
{
	char s[100];
	gets(s);
	if(is_balanced(s))
	{
		printf("well formed parentheses\n");
	}
	else
	{
		printf("not well formed parentheses\n");
	}
}