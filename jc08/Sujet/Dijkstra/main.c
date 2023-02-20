#include "Dijkstra.h"

void remplissage_maze(s_maze *maze)
{
    int i = 0;
    int j = 0;
    while (j < maze->size_x)
    {
        while (i < maze->size_y)
        {
            maze->maze[j][i] = -1;
            i++;
        }
        i = 0;
        j++;
    }
    maze->maze[0][0] = 0;
    maze->maze[0][1] = 0;
    maze->maze[0][2] = 0;
    maze->maze[1][2] = 0;
    maze->maze[2][2] = 0;
    maze->maze[2][3] = 0;
    maze->maze[3][3] = 0;
    maze->maze[3][4] = 0;
    maze->maze[3][5] = 0;
    maze->maze[3][6] = 0;
    maze->maze[3][7] = 0;
    maze->maze[2][7] = 0;
    maze->maze[1][7] = 0;
    maze->maze[0][7] = 0;
    maze->maze[2][8] = 0;
    maze->maze[3][8] = 0;
    maze->maze[7][1] = 0;
    maze->maze[8][1] = 0;
    maze->maze[3][2] = 0;
    maze->maze[1][0] = 0;
    maze->maze[2][0] = 0;
    maze->maze[3][0] = 0;
    maze->maze[4][0] = 0;
    maze->maze[4][1] = 0;
    maze->maze[4][2] = 0;
    maze->maze[3][2] = 0;
    return;
}
int main(int *argc, char **argv)
{
    int i = 0;
    s_maze *maze;
    maze = malloc(sizeof(s_maze));
    maze->size_x = 9;
    maze->size_y = 9;
    maze->maze = malloc(maze->size_x * sizeof(int *));
    while (i < maze->size_y)
    {
        maze->maze[i] = malloc(maze->size_y * sizeof(int));
        i++;
    }
    s_point *start;
    s_point *end;
    start = malloc(sizeof(s_point));
    end = malloc(sizeof(s_point));
    start->x = 0;
    start->y = 0;
    end->x = 3;
    end->y = 8;
    remplissage_maze(maze);
    dijkstra(maze, start, end);
    return (0);
}