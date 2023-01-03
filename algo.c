#include "algo.h"
#include "edge.h"
#include "node.h"
#include <stdio.h>

void build_graph_cmd(pnode *head)
{
   
}

void insert_node_cmd(pnode *head)
{
    pnode temp_head = &head;
    pedge edges = NULL;
    pedge * head_edge = &edges;

    while (temp_head != NULL)
    {
        temp_head = &temp_head->next;
    }

    int num = 0;
    scanf("%d", &num);
    temp_head = createNode(num);
    temp_head->edges = *head_edge;
 
    int weight = 0;
    int node_num = 0;
    int res = 0;
    while ((res = scanf("%d", &weight)) != EOF)
    {
        if (res){
            break;
        }
        scanf("%d", &node_num);

        pnode temp_head1 = &head;
        pnode found_node = NULL;
        while (temp_head1 != NULL)
        {
            if (temp_head1->node_num == num){
                temp_head1 = &temp_head1->next;
                found_node = temp_head1;
                break;
            }
        }
        if (found_node == NULL)
        {
            found_node = createNode(node_num);
        }

        if(edges == NULL)
        {
            edges = createEdge(temp_head1, weight);
        }
        edges = &edges->next;
    }
}
