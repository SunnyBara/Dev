#include <stdlib.h>
#include <unistd.h>

typedef struct point
{
    int x;
    int y;
} s_point;

typedef struct maze
{
    int **maze;
    int size_x;
    int size_y;
} s_maze;

typedef struct sommet
{
    struct sommet *next;
    s_point *point;
    int marqueur;
} s_sommet;
typedef struct file
{
    s_sommet *head;
    s_sommet *tail;
} s_file;

typedef struct listing
{
    struct listing *next;
    s_sommet *s;
    int nombresommet;
} s_listing;

typedef struct path
{
    char path;
    struct path *next;
} s_path;
void dijkstra(s_maze *maze, s_point *start, s_point *end);
