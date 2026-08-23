#include <stdio.h>
#include "stack.h"

int main()
{
    int i[5] = {10,20,30,40,50};

    stack_t mystack;
    init_stack(&mystack);

    int j = 0;
    while(j < 5)
    {
        push(&mystack,i[j]);
        ++j;
    }
    disp(&mystack);

    int a;
    printf("Enter the position of element to remove from stack: ");
    scanf("%d",&a);
    int c = get_ith_element(&mystack,a);
    printf("Removed element: %d\n",c);
    disp(&mystack);

    int b, val;
    printf("Enter the position and value of element to replace in stack: ");
    scanf("%d %d",&b,&val);
    int d = set_ith_element(&mystack,b,val);
    printf("Replaced element: %d\n",d);
    disp(&mystack);
}