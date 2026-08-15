#include <stdio.h>
#include "stack.h"

int main()
{
	char str[MAX];
	scanf("%s", str);

	stack_t mystack;
	init_stack(&mystack);
	
	char *s = str; 
    char ch;

	while((ch = *s++) != 'c')
	{
		push(&mystack, ch);
	}
    
	int palin_check = 1;

	while(!is_empty(&mystack) && (ch = *s++) != '\0')
	{
		if(pop(&mystack) != ch)
		{
			printf("not a palindrome\n");
			palin_check = 0;
			break;
		}
	}

	if(palin_check == 1)
	{
		printf("is a palindrome\n");
	}
}