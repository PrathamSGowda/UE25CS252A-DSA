#include <stdio.h>
#include "list.h"

int main()
{
	int a[] = {10,20,30,40,50};
	int n = 5;
	
	list_t mylist;
	init_list(&mylist);
    printf("List after initialization\n");
    disp1(&mylist);
	
	for(int i = 0; i < n; ++i)
	{
		insert(&mylist, a[i]);
	}

    printf("List after insertion\n");
	disp2(&mylist);
    printf("List length : %d\n", find_length1(&mylist));

    delete(&mylist,30);
    printf("List after deleting an element\n");
    disp1(&mylist);
    printf("List length : %d\n", find_length2(&mylist));

    deinit_list(&mylist);
    printf("List after deinitialization\n");
    disp2(&mylist);
}