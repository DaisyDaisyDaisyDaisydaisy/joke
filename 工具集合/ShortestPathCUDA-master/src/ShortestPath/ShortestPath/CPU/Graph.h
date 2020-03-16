#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "../Macros.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    int num_vertices;
    int num_edges;
    int* adjMatrix;
}graph_t;

typedef struct edge
{
    int u;
    int v;
    int weight;
}edge_t;

typedef struct neighborhood
{
    int length;
    int* vertices;
}neighborhood_t;

graph_t* createGraph(int n);

void addEdge(graph_t* graph, int u, int v, int weight);

void addNode(graph_t* graph);

int getWeight(graph_t* graph, int u, int v);

/*
 * Returns 1 if they are connected, 0 otherwise
 */
int areConnected(graph_t* graph, int u, int v);

neighborhood_t* getNeighbors(graph_t* graph, int u);

void deleteGraph(graph_t* graph);

void showGraph(graph_t* graph);

void err_exit(char* msg);

graph_t* mapToGraph(int* map, int n, int m);

int* getShortestPath(int* previous, int n, int source, int dest);

#endif