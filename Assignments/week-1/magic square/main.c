#include <stdio.h>
#include "magic.h"

int main()
{
    int n = 5;
    int arr[5*5] = { 23, 12, 1, 20, 9,
                      4, 18, 7, 21, 15,
                     10, 24, 13, 2, 16,
                     11,  5, 19, 8, 22,
                     17,  6, 25, 14, 3 };

    int ans = check_magic_sq(arr,n);

    if (ans)
        printf("Matrix is a magic sqaure\n");
    else
        printf("Matrix is not a magic sqaure\n");

}