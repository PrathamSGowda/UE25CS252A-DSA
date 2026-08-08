#include <stdio.h>
#include "spiral.h"

int main()
{
    int r,c;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int *matrix = spiral_create(r,c);
    
    spiral_display(matrix,r,c);
}