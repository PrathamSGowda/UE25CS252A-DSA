#include <stdio.h>
#include "stack.h"

int eval(char *s)
{
	stack_t mystack;
	init_stack(&mystack);
	
	char ch;
	int val1; int val2; int val = 0;
	int is_digit = 0;
	while( (ch = *s++) != '\0')
	{
		// assuming all binary
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			val1 = pop(&mystack); val2 = pop(&mystack);
			switch(ch)
			{
				case '+' : push(&mystack, val2 + val1); break;
				case '-' : push(&mystack, val2 - val1); break;
				case '*' : push(&mystack, val2 * val1); break;
				case '/' : push(&mystack, val2 / val1); break;
			}
		}
		else if(ch >= '0'  && ch <= '9')
		{
			is_digit = 1;
			val = val * 10 + ch - '0';
		}
		else if(ch == ' ' && is_digit)
		{
			push(&mystack, val);
			val = 0;
			is_digit = 0;
		}
	}
	val = pop(&mystack);
	deinit_stack(&mystack);
	return val;
}

// well formed parentheses
int main()
{
	char s[100];
	printf("Enter expression in postfix : \n");
	gets(s);
	printf("result : %d\n", eval(s));

}