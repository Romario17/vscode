#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/dlinked_list.h"
#include "../include/la_graph.h"

typedef struct state
{
    int c;
    int m;
} State;

/**
 * @param c -> cannibals number
 * @param m -> missionaries number
 * @param max_members_per_group
 * 
 * @return bolean value
 */
bool validateState(State s, int max_members_per_group)
{
    if (s.m == 0 || s.m == s.c || s.m == max_members_per_group)
        return true;
    return false;
}

/**
 * @param c1 and c2 -> number of missionaries and cannibals of the left bank before the crossing
 * @param m1 and m2 -> number of missionaries and cannibals of the left bank after the crossing
 * 
 * @return bolean value
 */
bool extrapoledBoatCapacity(State s1, State s2, int max_boat_capacity)
{
    if(((s1.c + s1.m) - (s2.c + s2.m)) >= 1 && ((s1.c + s1.m) - (s2.c + s2.m)) <= max_boat_capacity)
        return true;
    return false;
}

/**
 * @param max_members_per_group
 * @param max_boat_capacity
 * 
 * @return representation of the problem of crossing cannibals and missionaries in graph
 */
LA_Graph *problemOfCannibalsAndMissionaries(int max_members_per_group, int max_boat_capacity)
{
    LA_Graph *graph = laGraph_create((max_members_per_group + 1) * (max_members_per_group + 1));
    State s1; // state of the left bank before crossing
    State s2; // state of the left bank after crossing

    for (s1.c = 0; s1.c <= max_members_per_group; s1.c++)
        for (s1.m = 0; s1.m <= max_members_per_group; s1.m++)
        {
            if (validateState(s1, max_members_per_group))
            {
                int c2_inf_lim = (s1.c > max_boat_capacity) ? (s1.c - max_boat_capacity) : 0;
                int m2_inf_lim = (s1.m > max_boat_capacity) ? (s1.m - max_boat_capacity) : 0;
                bool is_first = true;

                //printf("[%d, %d] -- adjacency list = {", s1.c, s1.m);
                for (s2.c = c2_inf_lim; s2.c <= s1.c; s2.c++)
                    for (s2.m = m2_inf_lim; s2.m <= s1.m; s2.m++)
                        if (validateState(s2, max_members_per_group))
                            if (extrapoledBoatCapacity(s1, s2, max_boat_capacity))
                            {
                                int id_orig = (s1.c * (max_members_per_group + 1)) + s1.m;
                                int id_dest = (s2.c * (max_members_per_group + 1)) + s2.m;
                                laGraph_insertEdge(graph, id_orig, id_dest);
                                /*if (is_first == true)
                                    is_first = false;
                                else
                                    printf(" -> ");
                                printf("[%d, %d]", s2.c, s2.m);*/
                            }
                //printf("}\n");
            }
        }
    return graph;
}

int main()
{
    printf("###### GRAPH WITH THE LEFT MARGIN STATES ######\n\n");
    LA_Graph *graph = problemOfCannibalsAndMissionaries(3, 2);
    laGraph_print(graph);
    laGraph_destroy(graph, false);
    return 0;
}