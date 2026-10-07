#include <stdio.h>
#include "stack.h"

int eval_postfix(char *s)
{
	stack_t mystack;
	init_stack(&mystack);
	
	char ch;
	while( (ch = *s++) != '\0')
	{
		if(ch != ' ')
		{
			push(&mystack, ch);
		}
	}
	int val = eval(pop(&mystack));
	deinit_stack(&mystack);
	return val;
}


int main()
{
	char s[100];
	printf("Enter expression in postfix : \n");
	gets(s);
	printf("result : %d\n", eval_postfix(s));

}