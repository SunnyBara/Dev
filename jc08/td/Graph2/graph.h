typedef struct node{
    int pos_x;
    int pos_y;
    struct node *next;
    struct link *link;
    struct graph *root;
}s_node;

typedef struct graph
{
    int nb_node;
    s_node *nodelist;
}s_graph;

typedef struct link
{
    struct link *next;
    s_node *link_to;    
    int cost;
}s_link;
s_node *new_node(int x, int y, s_graph *gr);
s_graph *new_graph(void);
s_link *new_link(void);
void add_link(s_node *node, int x, int y, int cost);
void del_link(s_node *node, int x, int y);
void add_node(s_graph *gr, int x, int y);
void del_node(s_graph *gr, int x, int y);
void print_node(s_node *n);
void print_graph(s_graph *gr);