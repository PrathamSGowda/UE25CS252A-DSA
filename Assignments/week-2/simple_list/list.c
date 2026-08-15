#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void deinit_list(list_t* ptr_list)
{
    node_t *temp;
    node_t *pres = ptr_list->head_;
    while(pres != NULL)
    {
        temp = pres;
        pres = pres->next_;
        free(temp);
    }
    ptr_list->head_ = NULL;
    ptr_list->length_ = 0;
}

void delete(list_t *ptr_list, int key)
{
	node_t *prev = NULL; 
	node_t *pres = ptr_list->head_;

	while(pres != NULL && pres->key_ < key)
	{
		prev = pres;
		pres = pres->next_;
	}

	if(pres != NULL && pres->key_ == key)
	{
		if(prev == NULL) // beginning
            ptr_list->head_ = pres->next_;
        else // middle or end
            prev->next_ = pres->next_;

        free(pres);
        ptr_list->length_--;
	}
}

int find_length1(list_t *ptr_list) // finding length using new function
{
    int count = 0;
    node_t *pres = ptr_list->head_;

    while(pres != NULL)
    {
        pres = pres->next_;
        count++;
    }

    return count;
}

int find_length2(list_t *ptr_list) // findinf length by returning int field in struct
{
    return ptr_list->length_;
}

// reused code from class
void init_list(list_t *ptr_list)
{
	ptr_list->head_ = NULL;
    ptr_list->length_ = 0;
}

void disp(list_t *ptr_list)
{
	node_t* pres = ptr_list->head_;
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
	
	// empty list 
	if(ptr_list->head_ == NULL)
	{
		ptr_list->head_ = temp;
		temp->next_ = NULL;
	}
	else // find the position
	{
		node_t* prev = NULL; 
		node_t* pres = ptr_list->head_;
		while(pres != NULL && pres->key_ < temp->key_)
		{
			prev = pres;
			pres = pres->next_;
		}
		// beginning 
		if(prev == NULL)
		{
			ptr_list->head_ = temp;
			temp->next_ = pres;
		}
		else // middle or end 
		{
			prev->next_ = temp;
			temp->next_ = pres;
		}
	}
	ptr_list->length_++;
}