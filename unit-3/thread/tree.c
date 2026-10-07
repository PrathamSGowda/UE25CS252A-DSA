#include <stdio.h>
#include <stdlib.h>
#include "tree.h" 
// binary tree :
//	- empty 
//	- node followed by left and right subtree

void init(tree_t *ptr_tree)
{
	ptr_tree->root_ = NULL;
}

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
node_t* insert_key(node_t* root, node_t* temp)
{
	if(root == NULL)
	{
		return temp;
	}
	else 
	{
		node_t* pres = root;
		while(pres != NULL)
		{
			// which subtree to insert 
			if(temp->key_ < pres->key_)
			{
				if(pres->lthread_ == 0)
				{
					pres = pres->left_;
				}
				else 
				{
					break;
				}
			}
			else 
			{
				if(pres->rthread_ == 0)
				{
					pres = pres->right_;
				}
				else 
				{
					break;
				}
			}
		} // end of while
		// have found a position to insert 
		// left subtree or right subtree 
		if(temp->key_ < pres->key_) // left
		{
			temp->left_ = pres->left_;
			temp->right_ = pres; // remains a thread
			
			pres->left_ = temp;
			pres->lthread_ = 0;
		}
		else // right
		{
			temp->right_ = pres->right_;
			temp->left_ = pres; // remains a thread
			
			pres->right_ = temp;
			pres->rthread_ = 0;
		}
	}
	return root;
}

void insert(tree_t *ptr_tree, int key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->key_ = key;
	temp->left_ = temp->right_ = NULL;
	// assume to be threads as the node becomes a leaf
	temp->lthread_ = temp->rthread_ = 1;
	ptr_tree->root_ = insert_key(ptr_tree->root_, temp);
}

node_t* leftmost(node_t *root)
{
	node_t* temp = root;
	if(root == NULL)
	{
		return NULL;
	}
	// if left of a node is a structural pointer 
	//	go to the left
	while(temp->lthread_ == 0)
	{
		temp = temp->left_;
	}
	return temp;
	
}

void disp_keys(node_t* root)
{
	node_t* temp = leftmost(root);
	while(temp != NULL)
	{
		printf("%d ", temp->key_);
		// find the inorder succssor
		if(temp->rthread_ == 1)
		{
			temp = temp->right_;
		}
		else 
			// find the smallest in the right subtree
		{
			temp = leftmost(temp->right_);
		}
	}
		
}


void disp(tree_t *ptr_tree)
{
	disp_keys(ptr_tree->root_); printf("\n\n");
}


