#ifndef LA_GRAPH_H
#define LA_GRAPH_H

#include <stdbool.h>

typedef struct graph LA_Graph;
typedef struct graph_search_result
{
    int *previous;
    float *distances;
} LA_Graph_SearchResult;

LA_Graph *laGraph_create(int number_of_vertex);
bool laGraph_insertEdge(LA_Graph *graph, int id_origin, int id_destiny);
bool laGraph_removeEdge(LA_Graph *graph, int id_origin, int id_destiny);
void laGraph_print(LA_Graph *graph);
LA_Graph_SearchResult *laGraph_BFS(LA_Graph *graph, int origin);
LA_Graph_SearchResult *laGraph_DFS(LA_Graph *graph, int origin);
LA_Graph_SearchResult *laGraph_DIJKSTRA(LA_Graph *graph, int origin);
void laGraph_destroy(LA_Graph *graph);
void laGraph_searchResultDestroy(LA_Graph_SearchResult *search_result);

#endif /* LA_GRAPH_H */