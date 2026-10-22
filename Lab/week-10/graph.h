#ifndef GRAPH_H
#define GRAPH_H
#define MAXSIZE 20 
struct graph
{
	int n_; // # of nodes 
	int e_; // # of edges 
	int a_[MAXSIZE][MAXSIZE]; // adjacency matrix
};
typedef struct graph graph_t;

enum topology
{
	RING,
	BUS,
	STAR,
	FULL_MESH,
	TREE,
	HYBRID,
	NOT_NETWORK
};
typedef enum topology topology_t;

void init_graph(graph_t *ptr_graph, int n);
void deinit_graph(graph_t *ptr_graph);
void add_edge(graph_t *ptr_graph, int from, int to);
void disp_adj_mat(graph_t *ptr_graph);
int dfs(graph_t *ptr_graph, int u);

int is_eulerian(graph_t *ptr_graph);
int is_star(graph_t *ptr_graph);
topology_t check_topology(graph_t *ptr_graph);

#endif 