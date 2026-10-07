#include <stdio.h>
#include "tree.h" 

int main()
{
	#if 0
	int a1[] = {40, 60, 20, 10, 30, 70, 50};
	int n1 = 7;
	tree_t t1;
	init(&t1);
	for(int i = 0; i < n1; ++i)
	{
		insert(&t1, a1[i]);
	}
	
	printf("tree inorder : ");
	inorder(&t1);
	printf("tree preorder : ");
	preorder(&t1);
	printf("tree postorder : ");
	postorder(&t1);
	
	
	
	printf("# of nodes : %d\n", count_nodes(&t1));
	printf("# of leaves : %d\n", count_leaves(&t1));
	
	int a2[] = {10, 20, 30, 40, 50, 60, 70};
	int n2 = 7;
	tree_t t2;
	init(&t2);
	for(int i = 0; i < n2; ++i)
	{
		insert(&t2, a2[i]);
	}	
	printf("tree : ");
	inorder(&t2);
	printf("# of nodes : %d\n", count_nodes(&t2));
	printf("# of leaves : %d\n", count_leaves(&t2));
	
	
	tree_t t3;
	init(&t3);
	printf("tree : ");
	inorder(&t3);
	printf("# of nodes : %d\n", count_nodes(&t3));
	printf("# of leaves : %d\n", count_leaves(&t3));

	printf("same : %d\n", are_same(&t1, &t1));
	printf("same : %d\n", are_same(&t1, &t2));
	
	
	tree_t t4;
	init(&t4);
	copy(&t1, &t4);
	printf("same : %d\n", are_same(&t1, &t4));
	#endif
	
	int a1[] = {40, 60, 20, 10, 30, 70, 50};
	int n1 = 7;
	tree_t t1;
	init(&t1);
	for(int i = 0; i < n1; ++i)
	{
		insert(&t1, a1[i]);
	}
	
	printf("tree inorder : ");
	inorder(&t1);
	
	
	delete_key(&t1, 10);
	inorder(&t1);
	delete_key(&t1, 70);
	inorder(&t1);
	delete_key(&t1, 20);
	inorder(&t1);
	delete_key(&t1, 60);
	inorder(&t1);	
	
	delete_key(&t1, 40);
	inorder(&t1);	
}