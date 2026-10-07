#include <stdio.h>
#include <stdlib.h>
#include "tree.h" 
// binary tree :
//	- empty 
//	- node followed by left and right subtree

void init(tree_t *ptr_tree)
{
	ptr_tree->root_ = -1;
	ptr_tree->count_ = 0;
}

int insert_recursive(node_t elem[], int root, int temp)
{
	if(root == -1)
	{
		root = temp;
	}
	else if(elem[root].key_ > elem[temp].key_)
	{
		elem[root].left_ = insert_recursive(elem, elem[root].left_, temp);
	}
	else
	{
		elem[root].right_ = insert_recursive(elem, elem[root].right_, temp);
	}
	return root;
}
void insert(tree_t *ptr_tree, int key)
{
	int temp = ptr_tree->count_++;
	ptr_tree->elem_[temp].key_ = key;
	ptr_tree->elem_[temp].left_ = ptr_tree->elem_[temp].right_ = -1;
	ptr_tree->root_ = insert_recursive(ptr_tree->elem_, ptr_tree->root_, temp);
}

void disp_recursive(node_t elem[], int temp)
{
		if(temp != -1)
		{
			disp_recursive(elem, elem[temp].left_);
			printf("%d ", elem[temp].key_);
			disp_recursive(elem, elem[temp].right_);
		}
		
}


void disp(tree_t *ptr_tree)
{
	disp_recursive(ptr_tree->elem_, ptr_tree->root_); printf("\n\n");
}


