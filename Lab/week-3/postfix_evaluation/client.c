#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"

int eval(char *exp)
{
    stack_t mystack;
    init_stack(&mystack);

    char ch;
    int val1, val2;
    int is_digit = 0;
    int val = 0;

    while( (ch = *exp++) != '\0')
    {
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (is_empty(&mystack))
            {
                printf("error: stack underflow\n");
                deinit_stack(&mystack);
                return -1;
            }
            val1 = pop(&mystack);

            if (is_empty(&mystack))
            {
                printf("error: stack underflow\n");
                deinit_stack(&mystack);
                return -1;
            }
            val2 = pop(&mystack);

            switch(ch)
            {
                case '+' : push(&mystack, val2 + val1); break;
                case '-' : push(&mystack, val2 - val1); break;
				case '*' : push(&mystack, val2 * val1); break;
				case '/' : 
                    if(val1 == 0)
                    {
                        printf("error: division by zero\n");
                        return -1;
                    }
                    else
                        push(&mystack, val2 / val1);
                    break;
                case '^' : push(&mystack, pow(val2,val1)); break;
            }
        }

        else if(ch >= '0' && ch <= '9')
        {
            is_digit = 1;
            val = val*10 + ch - '0';
        }

        else if(ch == ' ' && is_digit)
        {
            push(&mystack,val);
            val = 0;
            is_digit = 0;
        }
    }
    
    val = pop(&mystack);

    if (! is_empty(&mystack))
    {
        printf("error: leftover operands\n");
        deinit_stack(&mystack);
        return -1;
    }

    deinit_stack(&mystack);
    return val;
}

int main()
{
    while(1)
    {
        char exp[MAX];
        printf("Enter a postfix expression to be evaluated: \n");
        gets(exp);
        if (strcmp(exp, "exit") == 0)
            break;
        if(eval(exp) != -1)
            printf("Result of the postfix expression: %d\n", eval(exp));
    }
}