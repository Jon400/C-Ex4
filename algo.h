
typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ edge, *pedge;

pnode findNode(pnode, int);

void insert_node(pnode *, int);

int shortPath(pnode, int, int *, int);
void shortsPath_cmd(pnode);
int shortPathAll(pnode, int*, int *, int, int);

int shortPath1(pnode, int *, int);

