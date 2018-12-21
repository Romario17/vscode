#ifndef LA_GRAPH_H
#define LA_GRAPH_H

#include <stdbool.h>

typedef struct la_graph LA_Graph;

LA_Graph *laGraph_create(int number_of_vertex);
bool laGraph_insertData(LA_Graph *graph, int id, void *data);
bool laGraph_insertEdge(LA_Graph *graph, int id_origin, int id_destiny);
bool laGraph_removeEdge(LA_Graph *graph, int id_origin, int id_destiny);
void laGraph_destroy(LA_Graph *graph, bool destroy_data);

#endif /* LA_GRAPH_H */