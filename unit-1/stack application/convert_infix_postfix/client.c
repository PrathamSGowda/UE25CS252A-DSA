#include <stdio.h>
#include "stack.h"
int prec_in_str(char ch)
{
	char val;
	switch(ch)
	{
		case '(' : val = 3; break; // High
		case '*' :
		case '/' : val = 2; break;
		case '+' :
		case '-' : val = 1; break;
	}
	return val;
}
int prec_in_stack(char ch)
{
	char val;
	switch(ch)
	{
		case '(' : val = 0; break; // Low
		case '*' :
		case '/' : val = 2; break;
		case '+' :
		case '-' : val = 1; break;
	}
	return val;
}
void  convert(char *s, char *p)
{
	stack_t mystack;
	init_stack(&mystack);
	
	char ch;
	while((ch = *s++) != '\0')
	{
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(')
		{
			if(is_empty(&mystack))
			{
				push(&mystack, ch);
			}
			else 
			{
				while(! is_empty(&mystack) && 
					prec_in_str(ch) < prec_in_stack(peek(&mystack)))
				{
					*p++ = pop(&mystack);
					*p++ = ' ';
				}
				push(&mystack, ch);
			}
		}
		else if(ch == ')')
		{
			while((ch = pop(&mystack)) != '(')
			{
				*p++ = ch;
				*p++ = ' ';
			}
		}
		else
		{
			*p++ = ch;
		}
	} // while
	while(! is_empty(&mystack))
	{
		*p++ = pop(&mystack);
		*p++ = ' ';
	}
	*p = '\0';
	deinit_stack(&mystack);

}

// convert infix to postfix
int main()
{
	char s[100]; // infix 
	char p[100]; // postfix 
	printf("Enter an exp in infix : ");
	gets(s);
	convert(s, p);
	printf("infix : %s\n", s);
	printf("postfix : %s\n", p);
}