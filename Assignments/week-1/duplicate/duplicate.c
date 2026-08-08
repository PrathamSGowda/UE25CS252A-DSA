#include <stdio.h>
#include "duplicate.h"

int duplicate_remove(int *arr, int n)
{
    int i = 1;
    int temp = arr[0];
    for(int j=1; j<n; j++)
    {
        if(arr[j] != temp)
        {
            temp = arr[j];
            arr[i] = arr[j];
            i++;
        }
    }
    n = i;

    return n;
}