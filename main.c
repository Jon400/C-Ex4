#include "graph.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char res = '\0';
    pnode node;
    pnode * head = &node;
    //*head = NULL;

    while (scanf("%c", &res) !=EOF)
    {
        if (res == 'A')
        {
            build_graph_cmd(head);
        }
        else if (res == 'B')
        {
            insert_node_cmd(head);
        }
        else if (res == 'D')
        {
            delete_node_cmd(head);
        }
        else if (res == 'S')
        {
            shortsPath_cmd(*head);
        }
        else if (res == 'T')
        {
            TSP_cmd(*head);
        }  
    }

    deleteAllNodes(*head);       
    return 0;
}
