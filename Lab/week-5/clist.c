#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

void remove_next_node(node_t *pres)
{
	if(pres == NULL || pres->next_ == pres)
	{
		return;
	}
	else
	{
		node_t *temp = pres->next_;
		pres->next_ = pres->next_->next_;
		free(temp);
	}
}

void josephus(clist_t *ptr_clist, int k)
{
	node_t *pres = ptr_clist->head_;
	node_t *prev = NULL;
	node_t *end = ptr_clist->head_;
	
	while(end->next_ != ptr_clist->head_)
	{
		end = end->next_;
	}
	
	do
	{
		for(int i=0; i<k-1; ++i)
		{
			prev = pres;
			pres = pres->next_;
		}
		remove_next_node(pres);

	} while(end->next_ != end);
}


void remove_node(clist_t  *ptr_clist, int key)
{
	node_t *pres = ptr_clist->head_;
    node_t *prev = NULL;
	node_t *end;

	if(pres == NULL)
	{
		printf("clist empty\n");
	}
	else
	{
		do
		{
			if(pres->key_ == key)
			{
				if(pres == ptr_clist->head_)
				{
					end = ptr_clist->head_;
					while(end->next_ != ptr_clist->head_)
					{
						end = end->next_;
					}
					ptr_clist->head_ = pres->next_;
					end->next_ = pres->next_;
					free(pres);
				}

				else
				{
					prev->next_ = pres->next_;
					free(pres);
				}
			}

			prev = pres;
			pres = pres->next_;
		} while (pres != ptr_clist->head_);

		printf("key not found\n");
	}
}

static node_t* create_node(int key)
{
	node_t* temp;
	temp = (node_t*)malloc(sizeof(node_t));
	temp->key_ = key;
	temp->next_ = NULL;
	return temp;
}
void init_clist(clist_t *ptr_clist)
{
	ptr_clist->head_ = NULL;
}

void add(clist_t *ptr_clist, int val)
{
	node_t* temp = create_node(val);
	if(ptr_clist->head_ == NULL)
	{
		ptr_clist->head_ = temp;
		temp->next_ = temp;
	}
	else
	{
		temp->next_ = ptr_clist->head_->next_;
		ptr_clist->head_->next_ = temp;
	}
	
}

void disp(clist_t* ptr_clist)
{
	node_t* pres = ptr_clist->head_;
	if(pres == NULL)
	{
		printf("clist empty\n");
	}
	else
	{
		do 
		{
			printf("%d ", pres->key_);
			pres = pres->next_;
		} while(pres != ptr_clist->head_);
		printf("\n");
	}
}