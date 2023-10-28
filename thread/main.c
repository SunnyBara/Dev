#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct grid
{
    struct cell *firstcell;
    int n;
    int nbrzero;
    int cpt;
} s_grid;
typedef struct list
{
    int sizeoflist;
    char *list;
} s_list;
typedef struct cell
{
    int posx;
    int posy;
    char value;
    s_list *banlist;
    s_list *oklist;
    struct cell *next;
} s_cell;
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int testvalue(s_list *softban, char value)
{
    int cr = 0;
    int j = 0;
    while (j < softban->sizeoflist)
    {
        if (value == softban->list[j])
        {
            cr++;
            break;
        }
        j++;
    }
    return (cr);
}

void searchsolution(s_cell *current, int zero, s_grid *mygrid, s_list **softbanrow, s_list **softbancolumn, s_cell *save)
{
    while (current->value != '0')
    {
        current = current->next;
    }
    int k = 0;
    if (current->banlist->sizeoflist > current->oklist->sizeoflist)
    {

        while (k < current->oklist->sizeoflist)
        {
            if (!testvalue(softbanrow[current->posx], current->oklist->list[k]) && !testvalue(softbancolumn[current->posy], current->oklist->list[k]))
            {
                zero--;
                if (zero != 0 && current->next != NULL)
                {
                    softbanrow[current->posx]->list[softbanrow[current->posx]->sizeoflist] = current->oklist->list[k];
                    softbancolumn[current->posy]->list[softbancolumn[current->posy]->sizeoflist] = current->oklist->list[k];
                    softbancolumn[current->posy]->sizeoflist++;
                    softbanrow[current->posx]->sizeoflist++;
                    save = current;
                    searchsolution(current->next, zero, mygrid, softbanrow, softbancolumn, save);
                    zero++;
                    softbanrow[current->posx]->sizeoflist--;
                    softbancolumn[current->posy]->sizeoflist--;
                    softbanrow[current->posx]->list[softbanrow[current->posx]->sizeoflist] = ' ';
                    softbancolumn[current->posy]->list[softbancolumn[current->posy]->sizeoflist] = ' ';
                }
                else if (zero == 0)
                {
                    mygrid->cpt++;
                    return;
                }
            }
            k++;
        }
    }
    else if (current->banlist->sizeoflist <= current->oklist->sizeoflist)
    {
        while (k < mygrid->n)
        {
            if (!testvalue(current->banlist, k + '0') && !testvalue(softbanrow[current->posx], k + '0') && !testvalue(softbancolumn[current->posy], k + '0'))
            {
                zero--;
                if (zero != 0 && current->next != NULL)
                {
                    softbanrow[current->posx]->list[softbanrow[current->posx]->sizeoflist] = current->oklist->list[k];
                    softbancolumn[current->posy]->list[softbancolumn[current->posy]->sizeoflist] = current->oklist->list[k];
                    softbancolumn[current->posy]->sizeoflist++;
                    softbanrow[current->posx]->sizeoflist++;
                    save = current;
                    searchsolution(current->next, zero, mygrid, softbanrow, softbancolumn, save);
                    zero++;
                    softbanrow[current->posx]->sizeoflist--;
                    softbancolumn[current->posy]->sizeoflist--;
                    softbanrow[current->posx]->list[softbanrow[current->posx]->sizeoflist] = ' ';
                    softbancolumn[current->posy]->list[softbancolumn[current->posy]->sizeoflist] = ' ';
                }
                else if (zero == 0)
                {
                    mygrid->cpt++;
                    return;
                }
            }
            k++;
        }
    }

    return;
}

void fillrow(char *row, int i, s_grid *mygrid)
{
    int j = 0;
    while (j < mygrid->n)
    {
        if (row[j] == '0')
        {
            mygrid->nbrzero++;
        }
        s_cell *newunit;
        newunit = malloc(sizeof(s_cell));
        newunit->posx = i;
        newunit->posy = j;
        newunit->value = row[j];
        newunit->next = NULL;
        newunit->oklist = malloc(sizeof(s_list));
        newunit->oklist->list = malloc((mygrid->n + 1) * sizeof(char));
        newunit->oklist->sizeoflist = 0;
        newunit->banlist = malloc(sizeof(s_list));
        newunit->banlist->list = malloc((mygrid->n + 1) * sizeof(char));
        newunit->banlist->sizeoflist = 0;
        if (mygrid->firstcell == NULL)
        {
            mygrid->firstcell = newunit;
        }
        else
        {
            s_cell *tmp = mygrid->firstcell;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = newunit;
        }
        j++;
    }
    return;
}

int testbanlist(s_cell *currentcell, char value)
{

    s_list *tmplist = currentcell->banlist;
    int k = 0;
    int cr = 0;
    if (currentcell->value == '0' && value != '0')
    {
        while (k < tmplist->sizeoflist)
        {
            if (tmplist->list[k] == value)
            {
                cr++;
            }
            k++;
        }
    }
    else
    {
        cr = 1;
    }
    return (cr);
}

void fillbanlist(s_grid *mygrid)
{

    s_cell *currentcell = mygrid->firstcell;
    while (currentcell != NULL)
    {

        s_cell *tmp = mygrid->firstcell;
        while (tmp != NULL)
        {
            if ((tmp->posx == currentcell->posx || tmp->posy == currentcell->posy) && !(testbanlist(tmp, currentcell->value)))
            {
                tmp->banlist->list[tmp->banlist->sizeoflist] = currentcell->value;
                tmp->banlist->sizeoflist++;
            }
            tmp = tmp->next;
        }
        currentcell = currentcell->next;
    }
}

int testokaylist(s_cell *currentcell, char value)
{
    s_list *tmplist = currentcell->banlist;
    int k = 0;
    int cr = 0;
    if (currentcell->value == '0' && value != '0')
    {
        while (k < tmplist->sizeoflist)
        {
            if (tmplist->list[k] == value)
            {
                cr++;
            }
            k++;
        }
    }
    else
    {
        cr = 1;
    }
    return (cr);
}

void fillokaylist(s_grid *mygrid)
{
    int k;
    s_cell *tmp = mygrid->firstcell;
    while (tmp != NULL)
    {

        k = 0;
        while (k < mygrid->n)
        {
            k++;
            if (!(testokaylist(tmp, k + '0')))
            {
                tmp->oklist->list[tmp->oklist->sizeoflist] = k + '0';
                tmp->oklist->sizeoflist++;
            }
        }
        tmp = tmp->next;
    }
}
int main()
{
    // initialisation
    int n = 9;
    //   scanf("%d", &n);
    //   fgetc(stdin);
    s_grid *mygrid;
    mygrid = malloc(sizeof(s_grid));
    mygrid->n = n;
    mygrid->firstcell = NULL;
    mygrid->nbrzero = 0;
    s_list **softbanrow;
    softbanrow = malloc(n * sizeof(s_list *));
    int a = 0;
    while (a < n)
    {
        softbanrow[a] = malloc(sizeof(s_list));
        softbanrow[a]->list = malloc((n + 1) * sizeof(s_list));
        softbanrow[a]->sizeoflist = 0;
        a++;
    }
    s_list **softbancolumn;
    softbancolumn = malloc(n * sizeof(s_list *));
    a = 0;
    while (a < n)
    {
        softbancolumn[a] = malloc(sizeof(s_list));
        softbancolumn[a]->list = malloc((n + 1) * sizeof(s_list));
        softbancolumn[a]->sizeoflist = 0;
        a++;
    }
    s_cell *save;
    char *row;
    row = malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            row = "420789036";
        }
        else if (i == 1)
        {
            row = "200000003";
        }
        else if (i == 2)
        {
            row = "004000000";
        }
        else if (i == 3)
        {
            row = "900123007";
        }
        else if (i == 4)
        {
            row = "500231008";
        }
        else if (i == 5)
        {
            row = "700312009";
        }
        else if (i == 6)
        {
            row = "000000000";
        }
        else if (i == 7)
        {
            row = "300000004";
        }
        else if (i == 8)
        {
            row = "630907025";
        }
        fillrow(row, i, mygrid);
        /*char row[11];
        scanf("%[^\n]", row);
        fgetc(stdin);*/
    }
    fillbanlist(mygrid);
    fillokaylist(mygrid);
    s_cell *tmp = mygrid->firstcell;
    // tab = filltab(tab, mygrid);

    // game

    searchsolution(mygrid->firstcell, mygrid->nbrzero, mygrid, softbanrow, softbancolumn, save);
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    printf("nbre cpt  = %d \n", mygrid->cpt);
    return 0;
}