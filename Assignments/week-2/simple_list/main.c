#include <stdio.h>
#include "list.h" 

int main()
{
	int a[] = {10,20,30,40,50};
	int n = 5;
	
	list_t mylist;
	init_list(&mylist);
    printf("List after initialization\n");
    disp(&mylist);
	
	for(int i = 0; i < n; ++i)
	{
		insert(&mylist, a[i]);
	}

    printf("List after insertion\n");
	disp(&mylist);

    delete(&mylist,30);
    printf("List after deleting an element\n");
    disp(&mylist);

    deinit_list(&mylist);
    printf("List after deinitialization\n");
    disp(&mylist);
}