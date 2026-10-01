#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void init(dll_t* ptr_dlist)
{
	ptr_dlist->head_ = ptr_dlist->tail_ = NULL;
	ptr_dlist->MAX_PAGES = 0;
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
	ptr_dlist->MAX_PAGES = ptr_dlist->MAX_PAGES + 1;
}

void add_at_end(dll_t* ptr_dlist, int key)
{
	node_t* temp = create_node(key);
	temp->next_ = NULL;
	temp->prev_ = ptr_dlist->tail_;
	
	if(ptr_dlist->head_ == NULL)
	{
		ptr_dlist->head_ = temp;
	}
	else
	{
		ptr_dlist->tail_->next_ = temp;
	}
	ptr_dlist->tail_ = temp;
	ptr_dlist->MAX_PAGES = ptr_dlist->MAX_PAGES + 1;
}

int remove_in_begin(dll_t* ptr_dlist)
{
	int res;
	node_t* temp = ptr_dlist->head_;
	if(ptr_dlist->head_ == NULL)
	{
		printf("cannot delete; list empty\n");
	}
	else if(ptr_dlist->head_ == ptr_dlist->tail_)
	{
		res = ptr_dlist->head_->key_;
		ptr_dlist->head_ = NULL;
		ptr_dlist->tail_ = NULL;
	} 
	else
	{
		res = ptr_dlist->head_->key_;
		ptr_dlist->head_ =ptr_dlist->head_->next_;
		ptr_dlist->head_->prev_ = NULL;
	}
	free(temp);
	ptr_dlist->MAX_PAGES = ptr_dlist->MAX_PAGES - 1;
	return res;
}

int remove_at_end(dll_t* ptr_dlist)
{
	int res; res = ptr_dlist->tail_->key_;

	node_t* temp = ptr_dlist->tail_;
	if(ptr_dlist->head_ == NULL)
	{
		printf("cannot delete; list empty\n");
	}

	else if(ptr_dlist->head_ == ptr_dlist->tail_)
	{
		res = ptr_dlist->tail_->key_;
		ptr_dlist->head_ = NULL;
		ptr_dlist->tail_ = NULL;
	} 

	else 
	{
		res = ptr_dlist->tail_->key_;	
		ptr_dlist->tail_ =ptr_dlist->tail_->prev_;
		ptr_dlist->tail_->next_ = NULL;
	}
	free(temp);
	ptr_dlist->MAX_PAGES = ptr_dlist->MAX_PAGES - 1;
	return res;
}

int is_empty(dll_t* ptr_dlist)
{
	return ptr_dlist->head_ == NULL;
}

int is_full(dll_t* ptr_dlist)
{
	if(ptr_dlist->MAX_PAGES == 8)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
