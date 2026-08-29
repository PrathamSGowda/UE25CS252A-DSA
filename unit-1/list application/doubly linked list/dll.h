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
};
typedef struct dll dll_t;

void add_after_key(dll_t *ptr_dlist, int key, int val);
void add_before_key(dll_t *ptr_dlist, int key, int val);
void remove_node(dll_t *ptr_dlist, int key);

void init(dll_t* ptr_dlist);
void disp_forward(dll_t* ptr_dlist);
void disp_backward(dll_t* ptr_dlist);
// add in the beginning 
void add_in_begin(dll_t* ptr_dlist, int key);
// add at the end 
void add_at_end(dll_t* ptr_dlist, int key);
// remove in the beginning
void remove_in_begin(dll_t* ptr_dlist);
// remove at the end 
void remove_at_end(dll_t* ptr_dlist);

#endif
