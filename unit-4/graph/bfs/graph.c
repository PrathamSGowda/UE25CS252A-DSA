#include <stdio.h>
#include "queue.h"
#include "graph.h"

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

void bfs(graph_t *ptr_graph, int u)
{
	int n = ptr_graph->n_;
	int visited[n];
	for(int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}
	queue_t q;
	init(&q);
	
	visited[u] = 1;
	enqueue(&q, u);
	// do when the queue is not empty 
	while(! is_empty(&q))
	{
		u = dequeue(&q);
		printf("%d ", u);
		for(int v = 0; v < n; ++v)
		{
			if(ptr_graph->a_[u][v] && !visited[v])
			{
				visited[v] = 1;
				enqueue(&q, v);
			}
		
		}	
	}
	printf("\n");
	deinit(&q);
}