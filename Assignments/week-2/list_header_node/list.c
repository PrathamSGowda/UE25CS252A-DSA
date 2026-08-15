#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *ptr_list)
{
	ptr_list->head_ = (node_t*)malloc(sizeof(node_t));
	ptr_list->head_->next_ = NULL; 
}

void deinit_list(list_t *ptr_list)
{
	node_t* temp;
	node_t* pres = ptr_list->head_->next_;

	while(pres != NULL)
	{
		temp = pres;
		pres = pres->next_;
		free(temp);
	}

	ptr_list->head_->next_ = NULL;
}

void disp(list_t *ptr_list)
{
	node_t* pres = ptr_list->head_->next_;
	while(pres != NULL)
	{
		printf("%d ", pres->key_);
		pres = pres->next_;
	}
	printf("\n");
}

void insert(list_t* ptr_list, int key) 
{
	node_t* temp;
	temp = (node_t*)malloc(sizeof(node_t));
	temp->key_ = key;
	temp->next_ = NULL;

	node_t* prev = ptr_list->head_; 
	node_t* pres = ptr_list->head_->next_;
	while(pres != NULL && pres->key_ < temp->key_)
	{
		prev = pres;
		pres = pres->next_;
	}
	prev->next_ = temp;
	temp->next_ = pres;
}

void delete(list_t* ptr_list, int key)
{
	node_t* prev = ptr_list->head_; 
	node_t* pres = ptr_list->head_->next_;

	while(pres != NULL && pres->key_ < key)
	{
		prev = pres;
		pres = pres->next_;
	}

	if(pres != NULL && pres->key_ == key)
	{
		prev->next_ = pres->next_;
		free(pres);
	}
}