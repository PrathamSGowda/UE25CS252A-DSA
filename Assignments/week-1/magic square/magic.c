#include <stdio.h>
#include "magic.h"

int check_magic_sq(int *matrix, int n)
{
    int key = (n*(n*n+1))/2;
    
    for(int i=0; i<n; i++) // check rows
    {
        int sum = 0;
        for(int j=0; j<n; j++)
            sum += matrix[i*n + j];
        if(sum != key)
            return 0;
    }

    for(int j=0; j<n; j++) // check columns
    {
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += matrix[i*n + j];
        if(sum != key)
            return 0;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) // check primary diagonal
        sum += matrix[i*n + i];
    if(sum != key)
        return 0;

    sum = 0;
    for (int i = 0; i < n; i++) // check secondary diagonal
        sum += matrix[i * n + (n - 1 - i)];
    if (sum != key)
        return 0;

    return 1;

}