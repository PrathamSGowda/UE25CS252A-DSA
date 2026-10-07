#ifndef STACK_H
#define STACK_H
// use this to avoid multiple inclusion 
// in the same header file 

#define MAX 100
struct node 
{
	struct node* left_;
	struct node* right_;
	char ch_; // stands for an operator or an operand 
	// is better to use a union here
};
typedef struct node node_t;
// make a stack of tree nodes
struct stack 
{
	node_t* ch_[MAX];
	int top_; // indicate where the last element was filled
};
typedef struct stack stack_t;

void init_stack(stack_t *ptr_stack);
void deinit_stack(stack_t *ptr_stack);
void push(stack_t *ptr_stack, char ch);
node_t* pop(stack_t *ptr_stack);
node_t* peek(stack_t *ptr_stack);
int is_empty(stack_t *ptr_stack);
int is_full(stack_t *ptr_stack);
int eval(node_t* temp);
int eval_postfix(char *str);
#endif