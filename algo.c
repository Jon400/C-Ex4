#include "algo.h"
#include "edge.h"
#include "node.h"
#include "graph.h"
#include <stdio.h>

pnode findNode(pnode head, int num)
{
    pnode found_node = NULL;
    pnode temp_head = head;
    while (temp_head != NULL)
    {
        if (temp_head->node_num == num){
            temp_head = temp_head->next;
            found_node = temp_head;
            break;
        }
    }
    return found_node;
}

void build_graph_cmd(pnode *head)
{
    int num;
    pnode * temp_head = head;
    scanf("%d", &num);
    int res = 0;

    for (size_t i = 0; i < num; i++)
    {
        *temp_head = createNode(i + 1);      
        temp_head= &((*temp_head)->next);
    }

    while (scanf("%d", &res) != EOF)
    {
        insert_node_cmd(head);
    }
    
    
}

void insert_node_cmd(pnode *head)
{
    pnode temp_head = *head;
    pedge edges = NULL;
    pedge * head_edge = &edges;
    pnode found_node = NULL;


    while (temp_head != NULL)
    {
        temp_head = temp_head->next;
    }

    int num = 0;
    scanf("%d", &num);
    found_node = findNode(temp_head, num);

    if (found_node == NULL)
    {
        temp_head = createNode(num);
    }
    else
    {
        deleteEdge(found_node->edges);
        temp_head = found_node;
    }
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

        found_node = findNode(*head, node_num);

        if(edges == NULL)
        {
            edges = createEdge(found_node, weight);
        }
        edges = edges->next;
    }
}
