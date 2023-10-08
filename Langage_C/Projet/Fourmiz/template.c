#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

typedef struct element
{
    int X;
    int Y;
    int owner;
    char *unitname;
    int stock_food;
    int health;
    int ad;
    int action;
    s_elem *next;

} s_elem;
typedef struct skill
{
    int cX;
    int cY;
    int action;
    int move = 0;
    int attack = 1;
    int createpeon = 2;
    int createsoldier = 3;
    int createruche = 4;
    int dropphero = 5;
    int carryfood = 6;
    int dropfood = 7;

} s_skill;
typedef struct army
{
    int owner;
    s_elem *firstunit;
    struct army *next;
} s_army;
s_army *list;
s_elem *army1;
s_elem *army2;
int costsoldier;
int costbuilder;
int costruche;

void fillcell(int X, int Y, s_maap *list)
{
    s_maap *tmp;
    tmp = list;
    tmp->X = 0;
    tmp->Y = 0;
    int i = 0;
    int j = 1;
    while (i < X)
    {

        while (j < Y)
        {
            s_maap *newcell;
            newcell = malloc(sizeof(s_maap));
            newcell->X = i;
            newcell->Y = j;
            tmp->next = newcell;
            tmp = tmp->next;
            j++;
        }
        i++;
        j = 0;
    }
}

void deplacement_fourmis(s_elem *fourmis, int cX, int cY)
{
    s_maap *tmp;
    tmp = listcell;
    if (cX < fourmis->X - 1 || cX > fourmis->X + 1 || cY < fourmis->Y - 1 || cY > fourmis->Y + 1)
    {
        printf("déplacement de la fourmis en %d %d vers %d %d illegal\n", fourmis->X, fourmis->Y, cX, cY);
    }
    else
    {
        while (tmp->X != cX && tmp->Y != cY)
        {
            tmp = tmp->next;
        }
        //        tmp->state = fourmis->state;
        //       fourmis->state = 0;
    }
    return;
}

void add(s_elem *newunit, s_elem *army)
{
    if (army->unitname == NULL)
    {
        army->X = newunit->X;
        army->Y = newunit->Y;
        army->health = newunit->health;
        army->unitname = newunit->unitname;
        army->owner = newunit->owner;
        army->stock_food = newunit->stock_food;
    }
    else
    {
        s_elem *tmp = army;
        while (tmp != NULL)
        {
            tmp = tmp->next;
        }
        tmp = newunit;
    }
    return;
}

void buildarmy()
{
    list = malloc(sizeof(s_army));
    army1 = malloc(sizeof(s_elem));
    army1->owner = 1;
    army2 = malloc(sizeof(s_elem));
    army2->owner = 2;
    s_maap *tmp;
    tmp = maap;
    while (tmp != NULL)
    {
        if (tmp->state > 2 && tmp->state < 6)
        {
            if (tmp->X > tmp->Y)
            {
                create_unit(tmp, army1);
            }
            else if (tmp->X < tmp->Y)
            {
                add(tmp, army2);
            }
            else
            {
                tmp->state == (rand() % 3);
            }
        }
    }
}

int main(int *argc, char **argv)
{
    s_maap *maap;
    maap = malloc(sizeof(s_maap));
    maap = loadfile();
    buildarmy(maap);
    loadmaap();
    game();
    return (0);
}