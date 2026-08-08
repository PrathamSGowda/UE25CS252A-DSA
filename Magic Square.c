#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int n);

int main()
{
    int n;
    printf("Enter the size of square matrix : ");
    scanf("%d",&n);

    int *arr = (int *)malloc(n*n*sizeof(int));

    int pos = n/2;
    arr[pos] = 1;
    for(int i=2; i<n*n; i++)
    {
        
    
    }
    
    display(arr,n);
}

void display(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ", arr[i*n+j]);
        printf("\n");
    }
}