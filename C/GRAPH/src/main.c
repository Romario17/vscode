#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/dlinked_list.h"
#include "../include/la_graph.h"

/**
 * @param c -> cannibals number
 * @param m -> missionaries number
 * @param max_members_per_group
 * 
 * @return bolean value
 */
bool validateState(int c, int m, int max_members_per_group)
{
    if (m == 0 || m == c || m == max_members_per_group)
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
    int c1, m1; // number of missionaries and cannibals of the left bank before the crossing
    int c2, m2; // number of missionaries and cannibals of the left bank after the crossing
    //int s1, s2;                 // state before crossing and state after crossing
    int c2_inf_lim, m2_inf_lim; // inferior limit

    for (c1 = 0; c1 <= max_members_per_group; c1++)
        for (m1 = 0; m1 <= max_members_per_group; m1++)
        {
            if (validateState(c1, m1, max_members_per_group))
            {
                c2_inf_lim = (c1 > max_boat_capacity) ? (c1 - max_boat_capacity) : 0;
                m2_inf_lim = (m1 > max_boat_capacity) ? (m1 - max_boat_capacity) : 0;
                bool is_first = true;

                printf("[%d, %d] -- adjacency list = {", c1, m1);
                for (c2 = c2_inf_lim; c2 <= c1; c2++)
                    for (m2 = m2_inf_lim; m2 <= m1; m2++)
                        if (validateState(c2, m2, max_members_per_group))
                            if (((c1 + m1) - (c2 + m2)) >= 1 && ((c1 + m1) - (c2 + m2)) <= max_boat_capacity)
                            {
                                if (is_first == true)
                                    is_first = false;
                                else
                                    printf(" -> ");
                                printf("[%d, %d]", c2, m2);
                            }
                printf("}\n");
            }
        }
    return graph;
}

int main()
{
    printf("###### GRAPH WITH THE LEFT MARGIN STATES ######\n\n");
    LA_Graph *graph = problemOfCannibalsAndMissionaries(3, 2);
    laGraph_destroy(graph, false);
    return 0;
}