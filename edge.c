#include "edge.h"
#include <stdlib.h>

pedge createEdge(pnode node, int weight)
{
    pedge new_edge = (pedge)malloc(sizeof(edge));
    if(new_edge != NULL){
        new_edge->weight = weight;
        new_edge->endpoint = node;
        new_edge->next = NULL;
    }
    return new_edge;
}

void deleteEdge(pedge edgeTBD)
{
    if (edgeTBD == NULL)
    {
        return;
    }
    free(edgeTBD);
}

void deleteAllEdges(pedge edgeTBD)
{
    if (edgeTBD == NULL)
    {
        return;
    }
    deleteAllEdges(edgeTBD->next);
    deleteEdge(edgeTBD);
}