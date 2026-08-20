#ifndef LIST_H
#define LIST_H
#include "rect.h"

struct node 
{
	rect_t rect_;
	struct node *next_;
};
typedef struct node node_t;

struct list 
{
	node_t* head_;
};
typedef struct list list_t;

void init_poly(list_t* ptr_list);
void insert(list_t* ptr_list, int length, int breadth);
void disp(list_t* ptr_list);

#endif