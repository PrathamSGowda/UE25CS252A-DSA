#include <stdio.h>
#include "graph.h"

int main()
{
	graph_t g;
	int n = 8;
	init_graph(&g, n);
	int e = 11;
	
	char *s[] = {"AB", "AC", "BC", "BD", "CE", 
		"DE", "DF", "FG", "EG", "GH", "FH"};

	
	for(int i = 0; i < e; ++i)
	{
		add_edge(&g, s[i][0] - 'A',  s[i][1] - 'A');
	}
	
	disp_adj_mat(&g);
	printf("dfs : ");
	
	dfs(&g, 0); // A
	
	deinit_graph(&g);

}