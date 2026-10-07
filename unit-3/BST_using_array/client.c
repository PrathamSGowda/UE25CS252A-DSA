#include <stdio.h>
#include "tree.h" 

int main()
{
	int a1[] = {40, 60, 20, 10, 30, 70, 50};
	int n1 = 7;
	tree_t t1;
	init(&t1);
	for(int i = 0; i < n1; ++i)
	{
		insert(&t1, a1[i]);
	}
	printf("tree : ");
	disp(&t1);
	
	int a2[] = {10, 20, 30, 40, 50, 60, 70};
	int n2 = 7;
	tree_t t2;
	init(&t2);
	for(int i = 0; i < n2; ++i)
	{
		insert(&t2, a2[i]);
	}	
	printf("tree : ");
	disp(&t2);
	
	
	tree_t t3;
	init(&t3);
	printf("tree : ");
	disp(&t3);

}