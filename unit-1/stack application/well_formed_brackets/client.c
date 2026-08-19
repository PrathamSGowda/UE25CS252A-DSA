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
			push(&mystack, ')');
		}
		else if(ch == '[')
		{
			push(&mystack, ']');
		}
		if(ch == '{')
		{
			push(&mystack, '}');
		}
		else if(ch == ')' || ch == ']' || ch == '}')
		{
			is_valid = !(is_empty(&mystack) || ch != pop(&mystack));
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