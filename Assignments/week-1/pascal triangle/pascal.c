#include <stdio.h>
#include "pascal.h"

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * fact(n - 1);
}

void pascal(int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            printf(" ");
        }
        for (int k=0; k<=i; k++)
        {
            int value = fact(i)/(fact(k)*fact(i - k));
            printf("%d ", value);
        }
        printf("\n");
    }
}