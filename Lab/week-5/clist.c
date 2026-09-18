#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clist.h"

int delete_after(clist_t *ptr_clist)
{
    node_t *temp;

    if (ptr_clist->head_ == NULL)
    {
        return -1;
    }

    temp = ptr_clist->head_->next_;

    if (temp == ptr_clist->head_)
    {
        free(temp);
        ptr_clist->head_ = NULL;
        return 0;
    }

    ptr_clist->head_->next_ = temp->next_;

    free(temp);

    return 0;
}

void find_kth(clist_t* ptr_list, int k)
{
    int i;
    if (ptr_list->head_ == NULL || k < 1)
        return;
    for (i = 1; i < k; i++)
    {
        ptr_list->head_ = ptr_list->head_->next_;
    }
    printf("person %d (%s) executed\n",ptr_list->head_->next_->key_,ptr_list->head_->next_->name_);
    delete_after(ptr_list);
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

void add(clist_t *ptr_clist, int key, char name_[50])
{
    node_t* temp = (node_t*)malloc(sizeof(node_t));

    if(temp == NULL)
    {
        printf("full\n");
        exit(1);
    }

    temp->key_ = key;
    strcpy(temp->name_, name_);
    
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

    ptr_clist->head_ = ptr_clist->head_->next_;
}


void disp(clist_t *ptr_clist)
{
    node_t* pres = ptr_clist->head_;

    if(pres != NULL)
    {
        do
        {
            pres = pres->next_;
            printf("%d %s\n", pres->key_, pres->name_);
        }
        while(pres != ptr_clist->head_);
    }

    printf("\n");
}

void init(clist_t *ptr_clist)
{
    ptr_clist->head_ = NULL;
}

void deinit(clist_t *ptr_clist)
{
    node_t *pres;
    node_t *next;

    if (ptr_clist->head_ == NULL)
        return;

    pres = ptr_clist->head_->next_;

    while (pres != ptr_clist->head_)
    {
        next = pres->next_;
        free(pres);
        pres = next;
    }

    free(ptr_clist->head_);
    ptr_clist->head_ = NULL;
}