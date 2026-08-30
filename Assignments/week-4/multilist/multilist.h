#ifndef MULTILIST_H
#define MULTILIST_H

#define MAX 50

struct node_score
{
    int score_;
    struct node_score *next_;
};
typedef struct node_score score_t;

struct score_list
{
    score_t *head_;
};
typedef struct score_list score_list_t;

struct node_name
{
    char ch_[MAX]; // name of player
    int total_; // total runs scored
    struct node_name *next_; // pointer to next player
    struct score_list scores_; // head node of score list
};
typedef struct node_name name_t;

struct multilist
{
    name_t *head_;
};
typedef struct multilist multilist_t;

void init(multilist_t *ptr_multilist);
void add_data(multilist_t *ptr_multilist, char name[], int score);
void display(multilist_t *ptr_multilist);

#endif