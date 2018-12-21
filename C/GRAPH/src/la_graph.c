#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/dlinked_list.h"
#include "../include/la_graph.h"

typedef struct vertex
{
    void *data;
    DLinkedList *adjacency_list;
} Vertex;

struct la_graph
{
    int number_of_vertex;
    Vertex *vertex_list;
};

LA_Graph *laGraph_create(int number_of_vertex)
{
    if (number_of_vertex <= 0)
        return NULL;
    LA_Graph *graph = (LA_Graph *)malloc(sizeof(LA_Graph));
    graph->number_of_vertex = number_of_vertex;
    graph->vertex_list = (Vertex *)malloc(sizeof(Vertex) * number_of_vertex);
    for (int i = 0; i < number_of_vertex; i++)
        graph->vertex_list[i].adjacency_list = dlinkedList_create();
    return graph;
}

bool laGraph_insertData(LA_Graph *graph, int id, void *data)
{
    if (id >= 0 && id < graph->number_of_vertex)
    {
        graph->vertex_list[id].data = data;
        return true;
    }
    return false;
}

bool laGraph_insertEdge(LA_Graph *graph, int id_origin, int id_destiny)
{
    if ((id_origin >= 0 && id_origin < graph->number_of_vertex) &&
        (id_destiny >= 0 && id_destiny < graph->number_of_vertex))
    {
        dlinkedList_insertLast(graph->vertex_list[id_origin].adjacency_list,
                               &graph->vertex_list[id_destiny]);
        return true;
    }
    return false;
}

bool laGraph_removeEdge(LA_Graph *graph, int id_origin, int id_destiny)
{
    if ((id_origin >= 0 && id_origin < graph->number_of_vertex) &&
        (id_destiny >= 0 && id_destiny < graph->number_of_vertex))
    {
        DLinkedList *adj_list = graph->vertex_list[id_origin].adjacency_list;
        for (dlinkedList_itrBegin(adj_list); !dlinkedList_itrEnd(adj_list); dlinkedList_itrNext(adj_list))
            if(&(graph->vertex_list[id_destiny]) == dlinkedList_itrGet(adj_list))
                dlinkedList_itrRemoveCurrent(adj_list);
        return true;
    }
    return false;
}

void laGraph_destroy(LA_Graph *graph, bool destroy_data)
{
    for (int i = 0; i < graph->number_of_vertex; i++)
    {
        if (destroy_data && (graph->vertex_list[i].data != NULL))
            free(graph->vertex_list[i].data);
        dlinkedList_destroy(graph->vertex_list[i].adjacency_list, false);
    }
    free(graph->vertex_list);
    free(graph);
}