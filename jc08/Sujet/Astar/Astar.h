
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
typedef struct point
{
    int x;
    int y;
} s_point;
typedef struct openlist
{
    struct openlist *prev;
    struct openlist *next;
    s_node *node;
    int globalcost;

}s_openlist;

s_node *new_node(int x, int y, s_graph *gr, s_point *end);
s_graph *new_graph(void);
s_link *new_link(void);
void add_link(s_node *node, int x, int y, int cost, s_graph *gr, s_point *end);
void add_node(s_graph *gr,s_node *node, s_point *end);
void Astar(s_graph *g, s_point *start, s_point *end);
s_node *search_node(s_graph *gr, int x, int y);
