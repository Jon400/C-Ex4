typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

pedge createEdge(pnode, int);

void deleteEdge(pedge);

void deleteAllEdges(pedge);