#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/dlinked_list.h"
#include "../include/fifo.h"
#include "../include/la_graph.h"

typedef struct vertex
{
    int id;
    DLinkedList *adjacency_list;
} Vertex;

struct graph
{
    Vertex *vertex_list;
    int number_of_vertex;
};

LA_Graph *laGraph_create(int number_of_vertex)
{
    if (number_of_vertex <= 0)
        return NULL;
    LA_Graph *graph = (LA_Graph *)malloc(sizeof(LA_Graph));
    graph->vertex_list = (Vertex *)malloc(sizeof(Vertex) * number_of_vertex);
    graph->number_of_vertex = number_of_vertex;
    for (int i = 0; i < number_of_vertex; i++)
    {
        graph->vertex_list[i].id = i;
        graph->vertex_list[i].adjacency_list = NULL;
    }
    return graph;
}

bool laGraph_insertEdge(LA_Graph *graph, int id_origin, int id_destiny)
{
    if ((id_origin >= 0 && id_origin < graph->number_of_vertex) &&
        (id_destiny >= 0 && id_destiny < graph->number_of_vertex))
    {
        if (graph->vertex_list[id_origin].adjacency_list == NULL)
            graph->vertex_list[id_origin].adjacency_list = dlinkedList_create();
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
        if (adj_list == NULL)
            return false;
        for (dlinkedList_itrBegin(adj_list); !dlinkedList_itrEnd(adj_list); dlinkedList_itrNext(adj_list))
            if (&(graph->vertex_list[id_destiny]) == dlinkedList_itrGet(adj_list))
                dlinkedList_itrRemoveCurrent(adj_list);
        if (dlinkedList_empty(adj_list))
        {
            dlinkedList_destroy(adj_list, false);
            graph->vertex_list[id_origin].adjacency_list = NULL;
        }
        return true;
    }
    return false;
}

void laGraph_print(LA_Graph *graph)
{
    for (int i = 0; i < graph->number_of_vertex; i++)
    {
        DLinkedList *adj_list = graph->vertex_list[i].adjacency_list;
        printf("[%d] -- adjacency list = {", i);
        if (adj_list != NULL)
        {
            bool is_first = true;
            for (dlinkedList_itrBegin(adj_list); !dlinkedList_itrEnd(adj_list); dlinkedList_itrNext(adj_list))
            {
                if (is_first == true)
                    is_first = false;
                else
                    printf("->");
                printf("[%d]", (*(Vertex *)dlinkedList_itrGet(adj_list)).id);
            }
        }
        printf("}\n");
    }
}

LA_Graph_SearchResult *laGraph_BFS(LA_Graph *graph, int origin)
{

}

LA_Graph_SearchResult *laGraph_DFS(LA_Graph *graph, int origin)
{

}

LA_Graph_SearchResult *laGraph_DIJKSTRA(LA_Graph *graph, int origin)
{

}

void laGraph_destroy(LA_Graph *graph)
{
    for (int i = 0; i < graph->number_of_vertex; i++)
    {
        if (graph->vertex_list[i].adjacency_list != NULL)
            dlinkedList_destroy(graph->vertex_list[i].adjacency_list, false);
    }
    free(graph->vertex_list);
    free(graph);
}

void laGraph_searchResultDestroy(LA_Graph_SearchResult *search_result)
{
    free(search_result->distances);
    free(search_result->previous);
}
