#include "Dijkstra.h"
#include <stdio.h>

s_sommet *create_sommet(int x, int y, int marqueur, s_listing *list)
{
    s_point *point;
    s_sommet *sommet;
    point = malloc(sizeof(s_point));
    point->x = x;
    point->y = y;
    sommet = malloc(sizeof(s_sommet));
    sommet->point = point;
    sommet->marqueur = marqueur + 1;
    sommet->next = NULL;
    list->nombresommet = list->nombresommet + 1;
    if (list->s == NULL)
    {
        list->s = sommet;
    }
    else
    {
        s_listing *new;
        new = malloc(sizeof(s_listing));
        new->s = sommet;
        s_listing *tmp;
        tmp = list;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
    return (sommet);
}
s_sommet *search_sommet(s_listing *list, int x, int y)
{
    s_listing *tmp;
    tmp = list;
    while (tmp != NULL && (tmp->s->point->x != x || tmp->s->point->y != y))
    {
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        return (NULL);
    }
    return (tmp->s);
}

void add_file(s_maze *maze, int x, int y, s_file *file, int marqueur, s_listing *list)
{
    s_sommet *sommet;
    sommet = create_sommet(x, y, marqueur, list);
    if (file->head == NULL)
    {
        file->head = sommet;
    }
    else if (file->head->next == NULL)
    {
        file->tail = sommet;
        file->head->next = sommet;
    }
    else
    {
        file->tail->next = sommet;
        file->tail = file->tail->next;
    }
    return;
}

s_sommet *defile(s_file *file)
{
    printf("defile marqueur : %i\n", file->head->marqueur);
    s_sommet *save;
    save = file->head;
    file->head = file->head->next;
    return (save);
}

void create_path(s_listing *list, int x, int y, char *path)
{
    s_sommet *end;
    s_sommet *save;
    s_sommet *save2;
    end = search_sommet(list, x, y);
    int i = end->marqueur;
    save = end;
    while (i > 0)
    {
        i--;
        end = save;
        end = search_sommet(list, save->point->x, save->point->y + 1);
        if (end != NULL && end->marqueur == save->marqueur - 1)
        {
            path[i] = 'L';
            save2 = end;
        }
        end = save;
        end = search_sommet(list, save->point->x + 1, save->point->y);
        if (end != NULL && end->marqueur == save->marqueur - 1)
        {
            path[i] = 'U';
            save2 = end;
        }
        end = save;
        end = search_sommet(list, save->point->x, save->point->y - 1);
        if (end != NULL && end->marqueur == save->marqueur - 1)
        {
            path[i] = 'R';
            save2 = end;
        }
        end = save;
        end = search_sommet(list, save->point->x - 1, save->point->y);
        if (end != NULL && end->marqueur == save->marqueur - 1)
        {
            path[i] = 'D';
            save2 = end;
        }
        save = save2;
    }
    return;
}

void printpath(char *path, s_listing *list, int x, int y)
{
    char writ[1];
    int i = 1;
    s_sommet *stop;
    stop = search_sommet(list, x, y);
    write(STDOUT_FILENO,"[",1);
    while (i < stop->marqueur)
    {
        writ[0] = path[i];
        write(STDOUT_FILENO, writ, 1);
        i++;
    }
    write(STDOUT_FILENO, "]\n", 2);
}

char *check_voisins(s_maze *maze, s_sommet *position, s_point *end, s_file *file, s_listing *list)
{
    s_sommet *test;
    if (position->point->y == end->y && position->point->x == end->x)
    {
        printf("fin de parcours\n");
        s_sommet *fin;
        fin = search_sommet(list, end->x, end->y);
        char path[fin->marqueur];
        create_path(list, end->x, end->y, path);
        printpath(path, list, end->x, end->y);
        return ("end");
    }
    if (position->point->y != 0)
    {
        test = search_sommet(list, position->point->x, position->point->y - 1);
        if (maze->maze[position->point->x][position->point->y - 1] == 0 && test == NULL)
        {
            add_file(maze, position->point->x, position->point->y - 1, file, position->marqueur, list);
        }
    }
    if (position->point->x != maze->size_x - 1)
    {
        test = search_sommet(list, position->point->x + 1, position->point->y);
        if (maze->maze[position->point->x + 1][position->point->y] == 0 && test == NULL)
        {
            add_file(maze, position->point->x + 1, position->point->y, file, position->marqueur, list);
        }
    }
    if (position->point->y != maze->size_y - 1)
    {
        test = search_sommet(list, position->point->x, position->point->y + 1);
        if (maze->maze[position->point->x][position->point->y + 1] == 0 && test == NULL)
        {
            add_file(maze, position->point->x, position->point->y + 1, file, position->marqueur, list);
        }
    }
    if (position->point->x != 0)
    {
        test = search_sommet(list, position->point->x - 1, position->point->y);
        if (maze->maze[position->point->x - 1][position->point->y] == 0 && test == NULL)
        {

            add_file(maze, position->point->x - 1, position->point->y, file, position->marqueur, list);
        }
    }
    return ("ok");
}

void dijkstra(s_maze *maze, s_point *start, s_point *end)
{
    s_file *file;
    s_sommet *sommet;
    s_listing *list;
    char *state;
    list = malloc(sizeof(s_listing));
    list->next = NULL;
    list->nombresommet = 0;
    list->s = NULL;
    file = malloc(sizeof(s_file));
    file->head = NULL;
    file->tail = NULL;
    if (maze->maze[start->x][start->y] != 0)
    {
        printf("position de départ illegal");
        return;
    }
    sommet = create_sommet(start->x, start->y, 0, list);
    check_voisins(maze, sommet, end, file, list);
    while (file->head != NULL)
    {
        sommet = defile(file);
        state = check_voisins(maze, sommet, end, file, list);
        if (state == "end")
        {
            break;
        }
    }
}