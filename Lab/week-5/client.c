#include <stdio.h>
#include "clist.h"

int main()
{
    clist_t list;
    int n, k;
    int i;

    init(&list);

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter the count k to be removed: ");
    scanf("%d", &k);

    for (i = 1; i <= n; i++)
    {
        char name_temp[50];
        printf("Enter name: ");
        scanf("%s", name_temp);
        add(&list, i, name_temp);
    }

    printf("\nInitial list:\n");
    disp(&list);

    printf("\nElimination order:\n");

    for (i=1; i<n; i++)
    {
        find_kth(&list, k);
    }

    printf("\nSurvivor:\n");
    disp(&list);

    deinit(&list);

    return 0;
}