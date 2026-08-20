#include <stdio.h>
#include "list.h"

int main()
{
    int l[50];
    int b[50];
    int n;
    printf("Enter the number of rectangles to be stored : ");
    scanf("%d",&n);
    for(int i = 0; i<n; i++)
    {
        printf("Enter length and breadth for rectangle %d : ",i+1);
        scanf("%d %d",&l[i],&b[i]);
    }

    list_t myrect;

    for(int i = 0; i < n; ++i)
	{
		insert(&myrect, l[i], b[i]);
	}
    disp(&myrect);

}