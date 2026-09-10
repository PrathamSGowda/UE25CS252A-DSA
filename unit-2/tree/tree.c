#include <stdio.h>
#include <stdlib.h>
#include "tree.h" 

void init(tree_t* ptr_tree)
{
	ptr_tree->root_ = NULL;
}
	
void insert(tree_t* ptr_tree, int key);

// binary tree 
//	1. empty 
//  2. root followed by two sub trees left and right


// inorder traversal :
//	if tree is not empty
//		traverse the left sub tree in order 
//		visit the root 
//		traverse the right sub tree in order
void disp_recursive(node_t* root)
{
	if(root != NULL)
	{
		disp_recursive(root->left_);
		printf("%d ", root->key_);
		disp_recursive(root->right_);
	}
}

void disp(tree_t* ptr_tree)
{
	printf("tree : ");
	disp_recursive(ptr_tree->root_);
	printf("\n");
}
// binary tree
//	binary search tree
node_t* insert_recursive(node_t* root, node_t* temp)
{
	if(root == NULL)
	{
		root = temp;
	}
	else if(root->key_ > temp->key_)
	{
		root->left_ = insert_recursive(root->left_, temp);
	}
	else 
	{
		root->right_ = insert_recursive(root->right_, temp);
	}
		
	return root;
}

void insert(tree_t* ptr_tree, int key)
{
	// make a node 
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->key_ = key;
	temp->left_ = temp->right_ = NULL; 
	// always add new nodes as leaves
	
	ptr_tree->root_ = insert_recursive(ptr_tree->root_, temp);
}

int count_nodes_recursive(node_t* root)
{
	if(root == NULL)
	{
		return 0;
	}
	else 
	{
		return 1 + count_nodes_recursive(root->left_) 
			+ count_nodes_recursive(root->right_);
	}
}

int count_nodes(tree_t* ptr_tree)
{
	return count_nodes_recursive(ptr_tree->root_);
}
