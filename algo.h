
typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ edge, *pedge;

pnode findNode(pnode, int);

int shortPath(pnode, int, int *, int);