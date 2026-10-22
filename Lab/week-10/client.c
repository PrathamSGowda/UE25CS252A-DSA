#include <stdio.h>
#include "graph.h"

int main()
{
    graph_t g;

    int v = 5;
    int e = 4;

    // int edge[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}}; // RING
    // int edge[][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}}; // STAR

    int edge[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}}; // BUS

    init_graph(&g, v);

    for (int i = 0; i < e; i++)
    {
        add_edge(&g, edge[i][0], edge[i][1]);
    }

    printf("Adjaceny Matrix\n\n");

    disp_adj_mat(&g);

    printf("\nEulerian check: %s\n", is_eulerian(&g) ? "It is an Eulerian graph" : "It is not an Eulerian graph");
    printf("Star check: %s\n",is_star(&g) ? "Star" : "Not a star");

    printf("Network topology  : ");

    topology_t result = check_topology(&g);

    switch (result)
    {
        case RING:
            printf("Ring\n");
            break;
        case BUS:
            printf("Bus\n");
            break;
        case STAR:
            printf("Star\n");
            break;
        case FULL_MESH:
            printf("Full Mesh\n");
            break;
        case TREE:
            printf("Tree\n");
            break;
        case HYBRID:
            printf("Hybrid\n");
            break;
        case NOT_NETWORK:
            printf("Not a network\n");
            break;
    }

    deinit_graph(&g);

    return 0;
}