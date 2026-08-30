#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "multilist.h"

void init(multilist_t *ptr_multilist)
{
    ptr_multilist->head_ = NULL;
}

void display(multilist_t *ptr_multilist)
{
    name_t *pres_name = ptr_multilist->head_;
    while(pres_name != NULL)
    {
        printf("%s : ", pres_name->ch_);
        score_t *pres_score = pres_name->scores_.head_;
        while(pres_score != NULL)
        {
            printf("%d ", pres_score->score_);
            pres_score = pres_score->next_;
        }
        printf("    Total runs : %d", pres_name->total_);
        printf("\n");
        pres_name = pres_name->next_;
    }
}

void add_data(multilist_t *ptr_multilist, char name[], int score)
{
    score_t *new_score = (score_t *)malloc(sizeof(score_t));
    new_score->score_ = score;
    new_score->next_ = NULL;

    name_t *pres_name = ptr_multilist->head_;
    name_t *prev_name = NULL;

    int existing_player = 0;

    while(pres_name != NULL)
    {
        if(! strcmp(pres_name->ch_, name)) // already existing player check
        {
            existing_player = 1;
            score_t *pres_score = pres_name->scores_.head_;
            if(pres_score == NULL)
            {
                pres_name->scores_.head_ = new_score;
            }
            else
            {
                while(pres_score->next_ != NULL)
                {
                    pres_score = pres_score->next_;
                }
                pres_score->next_ = new_score;
            }
            pres_name->total_ += score;
        }
        prev_name = pres_name;
        pres_name = pres_name->next_;
    }

    name_t *new_name = (name_t *)malloc(sizeof(name_t));
    strcpy(new_name->ch_, name);
    new_name->total_ = score;
    new_name->next_ = NULL;
    new_name->scores_.head_ = new_score;
    
    if(! existing_player)
    {
        if(ptr_multilist->head_ == NULL) 
        {
            ptr_multilist->head_ = new_name;
        }
        else 
        {
            prev_name->next_ = new_name;
        }
    }
}