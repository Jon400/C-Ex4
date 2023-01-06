#include "node.h"
#include "edge.h"
#include <stdlib.h>

pnode createNode(int num)
{
    pnode new_node = (pnode)malloc(sizeof(node));
    if(new_node != NULL)
    {
        new_node->node_num = num;
        new_node->edges = NULL;
        new_node->next = NULL;
    }
}

void deleteNode(pnode nodeTBD)
{
    if (nodeTBD == NULL)
    {
        return;
    }
    
    if (nodeTBD->edges != NULL)
    {
        deleteAllEdges(nodeTBD->edges);
    }

    free(nodeTBD);
}

