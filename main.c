#include "graph.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pnode * head = (pnode*) malloc(sizeof(pnode));
    *head = NULL;
    build_graph_cmd(head);
    return 0;
}
