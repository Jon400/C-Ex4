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
            found_node = temp_head;
            break;
        }
        temp_head = temp_head->next;
    }
    return found_node;
}

void build_graph_cmd(pnode *head)
{
    int num;
    pnode * temp_head = head;
    scanf("%d", &num);
    char res = '\0';

    for (size_t i = 0; i < num; i++)
    {
        *temp_head = createNode(i);      
        temp_head= &((*temp_head)->next);
    }

    for (size_t i = 0; i < num; i++)
    {
        scanf("%c", &res);
        scanf("%c", &res);
        insert_node_cmd(head);
    }

}

void insert_node_cmd(pnode *head)
{
    pnode temp_head = *head;
    pedge edges = NULL; 
    pedge * head_edge = &edges;
    pedge * temp_edge_head = head_edge;
    pnode found_node = NULL;

    int num = 0;
    scanf("%d", &num);
    found_node = findNode(temp_head, num);

    if (found_node == NULL)
    {
        temp_head = createNode(num);
    }
    else
    {
        deleteAllEdges(found_node->edges);
        temp_head = found_node;
    }
 
    int weight = 0;
    int node_num = 0;
    int res = 0;
    while ((res = scanf("%d", &node_num)) != EOF)
    {
        if (!res){
            break;
        }
        scanf("%d", &weight);

        found_node = findNode(*head, node_num);

        if(*temp_edge_head == NULL)
        {
            *temp_edge_head = createEdge(found_node, weight);
            temp_head->edges = *head_edge;
        }
        temp_edge_head = &((*temp_edge_head)->next);
    }
}

void delete_node_cmd(pnode * head)
{
    int num = 0;
    pnode nodeTBD = NULL;
    pnode prev_node = *head;

    scanf("%d", &num);
    nodeTBD = findNode(*head, num);  

    // Loop on all edges
    pnode temp_node = *head;
    pedge * head_edge = NULL;
    while (temp_node != NULL)
    {
        head_edge = &(temp_node->edges);
        pedge prev_edge = *head_edge;

        if (*head_edge == NULL)
        {
            temp_node = temp_node->next;
            continue;
        }

        while (prev_edge->next != NULL)
        {
            if (prev_edge->next->endpoint == nodeTBD)
            {
                pedge edgeTBD = prev_edge->next;
                prev_edge->next = prev_edge->next->next;
                deleteEdge(edgeTBD);
            }
            prev_edge = prev_edge->next;
        }        

        prev_edge = *head_edge;
        if((*head_edge)->endpoint == nodeTBD)
        {
            *head_edge = (*head_edge)->next;
            deleteEdge(prev_edge);
            prev_edge = *head_edge;
        }

        temp_node = temp_node->next;
    }

    if (nodeTBD == *head)
    {
        head = &((*head)->next);
        deleteNode(nodeTBD);
        return;
    }

    while (prev_node->next != nodeTBD)
    {
        prev_node = prev_node->next;
    }
    prev_node->next = nodeTBD->next;
    deleteNode(nodeTBD);
    
}
