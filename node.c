#include "node.h"
#include <stdlib.h>

pnode createNode(int num)
{
    pnode new_node = (pnode)malloc(sizeof(node));
    if(new_node != NULL)
    {
        new_node->node_num = num;
        new_node->edges = NULL;
        new_node->node_num = NULL;
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
        free(nodeTBD->edges);
    }

    free(nodeTBD);
}

