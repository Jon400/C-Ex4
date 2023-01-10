#include "algo.h"
#include "edge.h"
#include "node.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

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
    int node_num = 0;
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
        scanf("%d", &node_num);
        insert_node(head, node_num);
    }

}

void insert_node_cmd(pnode *head)
{
    int num;
    pnode * temp_head = head;
    pnode found_node = NULL;
    scanf("%d", &num);
    found_node = findNode( * temp_head, num);
    while (*temp_head)
    {
        temp_head= &((*temp_head)->next);
    }
    if (found_node)
    {
        insert_node(head, num);
    }
    else
    {
        *temp_head = createNode(num);
        insert_node(head, num);
    }
}

void insert_node(pnode *head, int num)
{
    pnode temp_head = *head;
    pedge edges = NULL; 
    pedge * head_edge = &edges;
    pedge * temp_edge_head = head_edge;
    pnode found_node = NULL;

    //int num = 0;
    //scanf("%d", &num);
    found_node = findNode(temp_head, num);


    deleteAllEdges(found_node->edges);
    //found_node->edges = NULL;
    temp_head = found_node;
 
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
            else{
                prev_edge = prev_edge->next;
            }
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

void shortsPath_cmd(pnode node)
{
    // count num of nodes in graph
    pnode temp_node = node;
    int nodes_count = 0;
    while (temp_node)
    {
        nodes_count ++;
        temp_node = temp_node->next;
    }
    
    int * visited_nodes_arr = (int *) malloc(nodes_count * sizeof(int));
    int * dist_nodes_arr = (int *) malloc(nodes_count * sizeof(int));
    //initialize the array
    for (size_t i = 0; i < nodes_count; i++)
    {
        // that means this node is not visited yet
        visited_nodes_arr[i] = 0;
        dist_nodes_arr[i] = -1; // -1 = inf
    }
    
    int node_source = 0;
    int node_target = 0;
    scanf("%d", &node_source);
    scanf("%d", &node_target);

    pnode min_dist_node = findNode(node, node_source);
    dist_nodes_arr[node_source] = 0;
    while (min_dist_node)
    {
           pedge edges = min_dist_node->edges;
           while (edges)
           {
                int node_dist = dist_nodes_arr[edges->endpoint->node_num];
                int node_dist_new = dist_nodes_arr[min_dist_node->node_num] + edges->weight;
                if (node_dist == -1)
                {
                    dist_nodes_arr[edges->endpoint->node_num] = node_dist_new;
                }
                else {
                    dist_nodes_arr[edges->endpoint->node_num] = node_dist < node_dist_new ? node_dist : node_dist_new;
                }
                edges = edges->next;
           }
           visited_nodes_arr[min_dist_node->node_num] = 1;

           int min_dist = -1;
           min_dist_node = NULL;
           for (size_t i = 0; i < nodes_count; i++)
           {
                if (!visited_nodes_arr[i])
                {
                    if (min_dist == -1)
                    {
                        min_dist_node = findNode(node, i);
                    }
                    else if (dist_nodes_arr[i] < min_dist)
                    {   
                        min_dist_node = findNode(node, i);
                    }
                }
           }   
    }

    printf("Dijsktra shortest path: %d\n", dist_nodes_arr[node_target]);  
    free(visited_nodes_arr);
    free(dist_nodes_arr);
}

void TSP_cmd(pnode node)
{
    int k = 0;
    int res = -1;
    scanf("%d", &k);
    int * path_nodes = (int *) malloc(k * sizeof(int)); 

    for (size_t i = 0; i < k; i++)
    {
        scanf("%d", &path_nodes[i]);
    }
    
    pnode temp_node = node;
    int nodes_count = 0;
    while (temp_node)
    {
        nodes_count ++;
        temp_node = temp_node->next;
    }
    
    int * all_nodes = (int *) malloc(nodes_count * sizeof(int));

    temp_node = node;
    for (size_t i = 0; i < nodes_count; i++)
    {
        all_nodes[i] = temp_node->node_num;
        temp_node = temp_node->next;
    }
    
    res = shortPathAll(node, all_nodes, path_nodes, nodes_count, k);
    
    free(path_nodes);
    free(all_nodes);
    printf("TSP shortest path: %d\n", res);
}

int shortPathAll(pnode head, int * arr, int * path_nodes, int len, int k)
{
    int min = shortPath1(head, arr, len);;
    int res = -1;
    int temp = 0;
    for (size_t i = 0; i < len; i++)
    {
        int is_node = 1;
        for (size_t j = 0; j < k; j++)
        {
            if (arr[i] == path_nodes[j])
            {
                is_node = 0;
            }
        }
        
        if (is_node && arr[i] != -1)
        {
            temp = arr[i];
            arr[i] = -1;
            res = shortPathAll(head, arr, path_nodes, len, k);
            arr[i] = temp;
            if (min == -1 && res != -1)
            {
                min = res;
            }
            else if (res != -1)
            {
                min = res > min ? min : res;
            }
        }
    }
    return min;
}

int shortPath(pnode head, int start, int * arr, int len)
{

    pnode node = NULL;
    pedge edges = NULL;
    node = findNode(head, start);
    edges = node->edges;
    int temp = 0;
    int min_path = -1;
    int temp_path = -1;
    while (edges)
    {
        //min_path = -1;
        for (size_t i = 0; i < len; i++)
        {
            if (arr[i] != -1)
            {
                if (edges->endpoint->node_num == arr[i])
                {
                    temp = arr[i];
                    arr[i] = -1;
                    int temp_res = shortPath(head, temp, arr, len);
                    arr[i] = temp;
                    if (temp_res == -1)
                    {
                        temp_path = -1; 
                    }
                    else
                    {
                        temp_path = edges->weight + temp_res;
                    }
                }
            }
        }
        if (min_path == -1)
        {
            min_path = temp_path;
        }
        else
        {
            min_path = min_path > temp_path ? temp_path : min_path;
        }
        edges = edges->next;  
    }

    if (min_path == -1)
    {
        for (size_t i = 0; i < len; i++)
        {
            if (arr[i] != -1)
            {
                return -1;
            }
        }
        return 0; 
    }

    return min_path;
    
}

int shortPath1(pnode head, int * arr, int len)
{
    int * path_nodes = arr; 
    int res = -1;
    int min = 0;
    
    for (size_t i = 0; i < len; i++)
    {
        if (path_nodes[i] != -1)
        {
            int temp = path_nodes[i];
            path_nodes[i] = -1;
            min = shortPath(head, temp, path_nodes, len);
            path_nodes[i] = temp;
            if (min == -1)
            {
                continue;
            }
            if(res == -1)
            {
                res = min;
            }
            else if (res > min)
            {
                res = min;
            }
        }
    }
    return res;
}