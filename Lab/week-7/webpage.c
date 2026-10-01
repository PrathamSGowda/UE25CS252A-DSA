#include <stdio.h>
#include "webpage.h"

void openPage(dll_t* ptr_dlist, int url)
{
    if(! is_full(ptr_dlist))
    {
        add_at_end(ptr_dlist, url);
    }
    else
    {
        printf("The webpage dropped is : %d\n", ptr_dlist->head_->key_);
        remove_in_begin(ptr_dlist);
        add_at_end(ptr_dlist, url);
    }
    ptr_dlist->curr_ = ptr_dlist->tail_;
    printf("The webpage opened is : %d\n", ptr_dlist->curr_->key_);
}

void goBack(dll_t* ptr_dlist)
{
    if(is_empty(ptr_dlist))
    {
        printf("Empty cannot go back\n");
    }
    else if(ptr_dlist->curr_->prev_ == NULL)
    {
        printf("No history of webpages exist\n");
        remove_at_end(ptr_dlist);
    }
    else
    {
        ptr_dlist->curr_ = ptr_dlist->curr_->prev_;
        remove_at_end(ptr_dlist);
        printf("The current webpage is : %d\n", ptr_dlist->curr_->key_);
    }
}