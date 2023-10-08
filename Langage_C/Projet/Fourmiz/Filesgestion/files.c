#include "../data/data.h"
#include "../game/game.h"
// #include "allaction.h"

s_maap *fillmaap(int X, int Y, s_maap *maap)
{
    s_maap *tmp;
    tmp = maap;
    int i = 0;
    int j = 1;
    while (i < X)
    {

        while (j < Y)
        {
            s_maap *newcell;
            s_phero *newphero;
            newphero = malloc(sizeof(s_phero));
            newphero->ruche1 = 0;
            newphero->ruche2 = 0;
            newphero->gotfood1 = 0;
            newphero->gotfood2 = 0;
            newphero->fight1 = 0;
            newphero->fight2 = 0;
            newcell = malloc(sizeof(s_maap));
            newcell->X = i;
            newcell->Y = j;
            newcell->state = 0;
            newcell->phero = newphero;
            newcell->food = 0;
            newcell->next = NULL;
            tmp->next = newcell;
            tmp = tmp->next;
            j++;
        }
        i++;
        j = 0;
    }
    return (maap);
}

int mergename(char *head, char *tails, char *receiver)
{
    int i = 0;
    int j = 0;
    int cr = 0;
    while ((head[i] != '\n' && head[i] != '\0') && j < 30 && i < 31)
    {
        if (head[i] != ' ')
        {
            if (head[i] == '.')
            {
                i = 31;
            }
            else
            {
                receiver[j] = head[i];
                j++;
            }
        }
        i++;
    }
    i = 0;
    while (tails[i] != '\0' && j < 30)
    {
        if (tails[i] != '\n')
        {
            receiver[j] = tails[i];
            j++;
        }
        i++;
    }
    if (j == 30)
    {
        printf("Trops de caractères!\n le fichier ne sera pas creer\n");
        cr = 1;
    }
    return (cr);
}
s_maap *loadfile(s_maap *maap)
{
    FILE *load;
    char filename[30] = {0};
    char *get;
    int cr;
    char *extend = ".txt";
    get = malloc(30 * sizeof(char));
    printf("Entrer le nom du fichier à ouvrir\n");
    fgets(get, 30, stdin);
    cr = mergename(get, extend, filename);
    load = fopen(filename, "r");
    if (load == NULL)
    {
        printf("Le fichier %s  n'existe pas\n", filename);
        return (loadfile(maap));
    }
    char c;
    int size[2];
    int i = 0;
    while (i < 2)
    {
        c = fgetc(load);
        size[i] = c - '0';
        i++;
    }
    printf("X %d Y %d \n", size[0], size[1]);
    i = 0;
    maap = fillmaap(size[0], size[1], maap);
    s_maap *tmp;
    tmp = maap;
    while (tmp != NULL && i < ((size[0] + 1) * size[1]))
    {
        c = fgetc(load);
        if (c != '\n')
        {
            if (c == '2')
            {
                tmp->food = initialfood;
            }
            else
            {
                tmp->state = c - '0';
            }
            tmp = tmp->next;
        }
        i++;
    }
    fclose(load);
    return (maap);
}
