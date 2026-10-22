#include <stdio.h>
#include "graph.h"

int count_degree(graph_t *ptr_graph, int v)
{
	int n = ptr_graph->n_;
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		count += ptr_graph->a_[v][i];
	}

	return count;
}

int is_connected(graph_t *ptr_graph)
{
	int n = dfs(ptr_graph, 0);
	return n;
}

int is_eulerian(graph_t *ptr_graph)
{
	int n = ptr_graph->n_;
	int degree;
	for(int i = 0; i < n; i++)
	{
		degree = count_degree(ptr_graph, i);
		if(degree % 2 != 0)
		{
			return 0;
		}
	}
	return 1;
}

int is_star(graph_t *ptr_graph)
{
	if(ptr_graph->e_ == ptr_graph->n_ - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

topology_t check_topology(graph_t *ptr_graph)
{
    int n = ptr_graph->n_;
    int e = ptr_graph->e_;

    if(n < 2 || !is_connected(ptr_graph))
    {
        return NOT_NETWORK;
    }

    int degree;
    int degree1 = 0;
    int degree2 = 0;
    int ring = 1;
    int full_mesh = 1;

    for(int i = 0; i < n; i++)
    {
        degree = count_degree(ptr_graph, i);

        if(degree == 1)
            degree1++;

        if(degree == 2)
            degree2++;

        if(degree != 2)
            ring = 0;

        if(degree != n - 1)
            full_mesh = 0;
    }

    if(n >= 3 && ring)
    {
        return RING;
    }
    if(e == n - 1 && degree1 == 2 && degree2 == n - 2)
    {
        return BUS;
    }
    if(is_star(ptr_graph))
    {
        return STAR;
    }
    if(full_mesh)
    {
        return FULL_MESH;
    }
    if(e == n - 1)
    {
        return TREE;
    }
    return HYBRID;
}

void init_graph(graph_t *ptr_graph, int n)
{
	ptr_graph->n_ = n;
	ptr_graph->e_ = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			ptr_graph->a_[i][j] = 0;
		}
	}
}

void deinit_graph(graph_t *ptr_graph)
{
	ptr_graph->e_ = 0;
	int n = ptr_graph->n_;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			ptr_graph->a_[i][j] = 0;
		}
	}
	ptr_graph->n_ = 0;

}

void add_edge(graph_t *ptr_graph, int from, int to)
{
	++ptr_graph->e_;
	ptr_graph->a_[from][to] = 1;
	ptr_graph->a_[to][from] = 1;
}

void disp_adj_mat(graph_t *ptr_graph)
{
	int n = ptr_graph->n_;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			printf("%d ", ptr_graph->a_[i][j]);
		}
		printf("\n");
	}
}

void dfs_recursive(graph_t *ptr_graph, int n, int visited[], int u)
{
	//visit u 
	visited[u] = 1;
	// find nodes adjacent to u which are not visited 
	//	visit them recursively 
	for(int v = 0; v < n; ++v)
	{
		if(ptr_graph->a_[u][v] && !visited[v])
		{
			dfs_recursive(ptr_graph, n, visited, v);
		}
	}
}

int dfs(graph_t *ptr_graph, int u)
{
	int n = ptr_graph->n_;
	int visited[n];
	for(int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}
	dfs_recursive(ptr_graph, n, visited, u);

	int sum = 0;
	for(int i = 0; i<n; i++)
	{
		sum += visited[i];
	}

	if(sum == n)
		return 1;
	else
		return 0;
}