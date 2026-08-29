#include <stdio.h>
#include "clist.h"

int main()
{
	clist_t mylist;
	init_clist(&mylist);
	
	int a[] = {10, 20, 30, 40, 50};
	int n = 5;
	
	for(int i = 0; i < n; ++i)
	{
		add(&mylist, a[i]);
		disp(&mylist);
	}

	int key;
	printf("Enter key to be deleted : ");
	scanf("%d",&key);
	remove_node(&mylist,key);
	disp(&mylist);
}