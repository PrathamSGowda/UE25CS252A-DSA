#ifndef TREE_H
#define TREE_H 
struct node 
{
	int key_;
	struct node *left_;
	struct node *right_;
};
typedef struct node node_t;
struct tree
{
	node_t* root_;
};
typedef struct tree tree_t;

void init(tree_t* ptr_tree);
void insert(tree_t* ptr_tree, int key);
void disp(tree_t* ptr_tree);

int count_nodes(tree_t* ptr_tree);
#endif
