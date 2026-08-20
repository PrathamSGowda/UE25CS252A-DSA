#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_rect(list_t *ptr_list)
{
	ptr_list->head_ = NULL;
}

void disp(list_t *ptr_list)
{
	node_t* pres = ptr_list->head_;
	while(pres != NULL)
	{
		disp_rect(&pres->rect_);
		pres = pres->next_;
	}
	printf("\n");
}

void insert(list_t* ptr_list, int length, int breadth) 
{
	node_t* temp;
	temp = (node_t*)malloc(sizeof(node_t));
	set_rect(&temp->rect_, length, breadth);
	temp->next_ = NULL;
	
	if(ptr_list->head_ == NULL)
	{
		ptr_list->head_ = temp;
		temp->next_ = NULL;
	}
	else
	{
		node_t* prev = NULL; 
		node_t* pres = ptr_list->head_;
		while(pres != NULL && compare_rect(&pres->rect_, &temp->rect_) < 0)
		{
			prev = pres;
			pres = pres->next_;
		}
		if(prev == NULL)
		{
			ptr_list->head_ = temp;
			temp->next_ = pres;
		}
		else
		{
			prev->next_ = temp;
			temp->next_ = pres;
		}
	}
	
}