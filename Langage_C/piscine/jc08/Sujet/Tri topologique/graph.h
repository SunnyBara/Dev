typedef struct node
{
    int pos_x;
    int pos_y;
    int global_cost;
    int dist;
    int h;
    int closed;
    int open;
    struct node *next;
    struct link *link;
    struct graph *root;
    struct node *orig;
} s_node;

typedef struct cpt
{
    s_node **sort;
    int cpt;
} s_cpt;

typedef struct graph
{
    int nb_node;
    s_node *nodelist;
} s_graph;

typedef struct link
{
    struct link *next;
    s_node *link_to;
    int cost;
} s_link;
s_node *new_node(int x, int y, s_graph *gr);
s_graph *new_graph(void);
s_link *new_link(void);
void add_link(s_node *node, int x, int y, int cost);
void add_node(s_graph *gr, int x, int y);
s_node **topological_sort(s_graph *g);
void linkAtoB(s_node *A, s_node *B, s_link *lien, int cost);