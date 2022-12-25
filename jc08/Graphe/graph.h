typedef struct  adja
{
    int nb_node;
    int **mat;
}s_adja;
s_adja *create_adja(unsigned int nb_node);
void add_link( s_adja *adj, int x, int y, int cost);
void del_link(s_adja *adj, int x, int y);
void print_adja(s_adja *adj);