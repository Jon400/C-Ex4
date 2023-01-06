#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char res = '\0';
    pnode * head = (pnode*) malloc(sizeof(pnode));
    *head = NULL;

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
        
    }
    
    return 0;
}
