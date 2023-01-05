#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

void build_graph_cmd(pnode *);
void insert_node_cmd(pnode *);
void delete_node_cmd(pnode *);
void printGraph_cmd(pnode); //for self debug
void deleteGraph_cmd(pnode*);
void shortsPath_cmd(pnode);
void TSP_cmd(pnode);

#endif
