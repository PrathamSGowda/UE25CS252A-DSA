#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

node_t* create_node(int key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	if(temp == NULL)
	{
		perror("malloc failed\n");
	}
	else 
	{
		temp->key_ = key;
	}
	return temp;
	
}

void add_after_key(dll_t *ptr_dlist, int key, int val)
{
	node_t *temp = create_node(val);
	node_t *pres = ptr_dlist->head_;

	int key_found = 0;

	while(pres != NULL)
	{
		if(pres->key_ == key)
		{
			key_found = 1;
			if(pres->next_ == NULL)
			{
				add_at_end(ptr_dlist, val);
			}

			else
			{
				temp->prev_ = pres;
            	temp->next_ = pres->next_;

            	pres->next_->prev_ = temp;
            	pres->next_ = temp;
			}
		}
		pres = pres->next_;

	}

	if(key_found == 0)
		printf("key not found\n");
}

void add_before_key(dll_t *ptr_dlist, int key, int val)
{
	node_t *temp = create_node(val);
	node_t *pres = ptr_dlist->head_;

	int key_found = 0;

	while(pres != NULL)
	{
		if(pres->key_ == key)
		{
			key_found = 1;
			if(pres->prev_ == NULL)
			{
				add_in_begin(ptr_dlist, val);
			}

			else
			{
				temp->prev_ = pres;
            	temp->next_ = pres->next_;

            	pres->next_->prev_ = temp;
            	pres->next_ = temp;
			}
		}
		pres = pres->next_;

	}
	
	if(key_found == 0)
		printf("key not found\n");
}

void remove_node(dll_t *ptr_dlist, int key)
{
	node_t* pres = ptr_dlist->head_;
	int key_found = 0;

	while(pres != NULL)
	{
		if(pres->key_ == key)
		{
			key_found = 1;
			if(pres->prev_ == NULL)
			{
				remove_in_begin(ptr_dlist);
			}
			else if(pres->next_ == NULL)
			{
				remove_at_end(ptr_dlist);
			}
			else
			{
				pres->next_->prev_ = pres->prev_;
				pres->prev_->next_ = pres->next_;
				free(pres);
			}
		}
		pres = pres->next_;
	}
	if(key_found == 0)
		printf("key not found\n");
}

void init(dll_t* ptr_dlist)
{
	ptr_dlist->head_ = ptr_dlist->tail_ = NULL;
}

void disp_forward(dll_t* ptr_dlist)
{
	printf("forward display : ");
	node_t* temp = ptr_dlist->head_;
	while(temp)
	{
		printf("%d ", temp->key_);
		temp = temp->next_;
	}
	printf("\n");
}

void disp_backward(dll_t* ptr_dlist)
{
	printf("back display : ");
	node_t* temp = ptr_dlist->tail_;
	while(temp)
	{
		printf("%d ", temp->key_);
		temp = temp->prev_;
	}
	printf("\n");
}


// 1. empty list 
// 2. non-empty list
void add_in_begin(dll_t* ptr_dlist, int key)
{
	node_t* temp = create_node(key);
	temp->prev_ = NULL;
	temp->next_ = ptr_dlist->head_;
	if(ptr_dlist->head_ == NULL)
	{
		ptr_dlist->tail_ = temp;
	}
	else
	{
		ptr_dlist->head_->prev_ = temp;
	}
	ptr_dlist->head_ = temp;
}

// 1. empty list 
// 2. non-empty list
void add_at_end(dll_t* ptr_dlist, int key)
{
	node_t* temp = create_node(key);
	temp->next_ = NULL;
	temp->prev_ = ptr_dlist->tail_;
	
	if(ptr_dlist->head_ == NULL) // empty
	{
		ptr_dlist->head_ = temp;
	}
	else
	{
		ptr_dlist->tail_->next_ = temp;
	}
	ptr_dlist->tail_ = temp;
}

// remove the first node 
// 1. empty list 
// 2. single node list 
// 3. list with many nodes
void remove_in_begin(dll_t* ptr_dlist)
{
	node_t* temp = ptr_dlist->head_;
	if(ptr_dlist->head_ == NULL)
	{
		printf("cannot delete; list empty\n");
	}
	// single list node 
	else if(ptr_dlist->head_ == ptr_dlist->tail_)
	{
		ptr_dlist->head_ = NULL;
		ptr_dlist->tail_ = NULL;
	} 
	else // list with many nodes 
	{
		ptr_dlist->head_ =ptr_dlist->head_->next_;
		ptr_dlist->head_->prev_ = NULL;
	}
	free(temp);
}
// remove the last node 
// 1. empty list 
// 2. single node list 
// 3. list with many nodes
void remove_at_end(dll_t* ptr_dlist)
{
	node_t* temp = ptr_dlist->tail_;
	if(ptr_dlist->head_ == NULL)
	{
		printf("cannot delete; list empty\n");
	}
	// single list node 
	else if(ptr_dlist->head_ == ptr_dlist->tail_)
	{
		ptr_dlist->head_ = NULL;
		ptr_dlist->tail_ = NULL;
	} 
	else // list with many nodes 
	{
		ptr_dlist->tail_ =ptr_dlist->tail_->prev_;
		ptr_dlist->tail_->next_ = NULL;
	}
	free(temp);
}
