#ifndef DLL_H
#define DLL_H 
struct node
{
	int key_;
	struct node* prev_;
	struct node* next_;
};
typedef struct node node_t;

struct dll 
{
	node_t* head_;
	node_t* tail_;
	node_t* curr_;
	int MAX_PAGES;
};
typedef struct dll dll_t;
void init(dll_t* ptr_dlist);
void disp_forward(dll_t* ptr_dlist);
void disp_backward(dll_t* ptr_dlist);
void add_in_begin(dll_t* ptr_dlist, int key);
void add_at_end(dll_t* ptr_dlist, int key);
int remove_in_begin(dll_t* ptr_dlist);
int remove_at_end(dll_t* ptr_dlist);
int is_empty(dll_t *ptr_dlist);
int is_full(dll_t *ptr_dlist);
#endif 
