#ifndef TREE_H
#define TREE_H
struct node
{
	int key_;
	struct node *left_;
	struct node *right_;
	int lthread_; // 1 if thread ; 0 if structural
	int rthread_;
};
typedef struct node node_t;

struct tree 
{
	node_t* root_;
};
typedef struct tree tree_t;

void init(tree_t *ptr_tree);
void insert(tree_t *ptr_tree, int key);
void disp(tree_t *ptr_tree); // inorder


#endif