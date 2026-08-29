#include <stdio.h>
#include "dll.h"

int main()
{
	dll_t mylist;
	init(&mylist);
	int key;
	int opt;
	int val;
	printf("enter 1 add in beg; 2 add at end; 3: remove in begin "
		" 4 : remove at end 5 : disp forward  6 : disp back ; 7 : add after key; 8 : add before key; 9 : remove node "
		" enter 0 to stop : ");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : 	scanf("%d", &key);
						add_in_begin(&mylist, key);
						break;
			case 2 : 	scanf("%d", &key);
						add_at_end(&mylist, key);
						break;
			case 3 : 	remove_in_begin(&mylist);
						break;
			case 4 : 	remove_at_end(&mylist);
						break;
			case 5 : 	disp_forward(&mylist);
						break;
			case 6 : 	disp_backward(&mylist);
						break;
			case 7 :	scanf("%d %d", &key, &val);
						add_after_key(&mylist, key, val);
						break;
			case 8 : 	scanf("%d %d", &key, &val);
						add_before_key(&mylist, key, val);
						break;
			case 9 :    scanf("%d", &key);
						remove_node(&mylist, key);
						break;
		}
		printf("enter 1 add in beg; 2 add at end; 3: remove in begin "
			" 4 : remove at end 5 : disp forward  6 : disp back ; 7 : add after key; 8 : add before key; 9 : remove node "
			" enter 0 to stop : ");
		scanf("%d", &opt);
					
	}
	disp_forward(&mylist);
	disp_backward(&mylist);
}