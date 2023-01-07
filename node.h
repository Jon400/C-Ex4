
typedef struct edge_ edge, *pedge;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

pnode createNode(int);
void deleteNode(pnode);

void deleteAllNodes(pnode);