#include <stdio.h>
#include <stdlib.h>
#include "spiral.h"

int *spiral_create(int r, int c)
{
    int *matrix = (int *)malloc(r*c*sizeof(int));
    
    int top = 0;
    int bottom = r-1;
    int left = 0;
    int right = c-1;
    int n=1;

    while(top<=bottom && left<=right)
    {
        for(int i=left; i<=right; i++)
            matrix[top*c + i] = n++;
        top++;

        for(int i=top; i<=bottom; i++)
            matrix[i*c + right] = n++;
        right--;

        if(top<=bottom)
        {
            for(int i=right; i>=left; i--)
                matrix[bottom*c + i] = n++;
            bottom--;
        }

        if(left<=right)
        {
            for(int i=bottom; i>=top; i--)
                matrix[i*c + left] = n++;
            left++;
        }
    }
    
    return matrix;
}

void spiral_display(int *matrix, int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            printf("%d\t", matrix[i*c + j]);
        printf("\n");
    }
}