#include <stdio.h>
#include "stack.h"

int prec_in_str(char ch)
{
	int val;
	switch(ch)
	{
        case '^' : val = 3; break;
		case '(' : val = 4; break;
		case '*' :
		case '/' : val = 2; break;
		case '+' :
		case '-' : val = 1; break;
	}
	return val;
}

int prec_in_stack(char ch)
{
	int val;
	switch(ch)
	{
        case '^' : val = 3; break;
		case '(' : val = 0; break;
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
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == '^')
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

            while ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z') || (*s >= '0' && *s <= '9'))
            {
                *p++ = *s++;
            }

            *p++ = ' ';
        }
    }

	while(! is_empty(&mystack))
	{
		*p++ = pop(&mystack);
		*p++ = ' ';
	}
	*p = '\0';
	deinit_stack(&mystack);

}

int main()
{
	char infix[100];
	char postfix[100]; 
	printf("Enter an expression in infix: ");
	gets(infix);
	convert(infix, postfix);
	printf("infix : %s\n", infix);
	printf("postfix : %s\n", postfix);
}