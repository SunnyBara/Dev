#include "../data/data.h"
#include "../game/game.h"
void freetest(s_test *list)
{
    s_test *save;
    s_test *tmp = list;
    while (tmp != NULL)
    {
        save = tmp;
        tmp = tmp->next;
        //        printf("free de %d\n", save->good);
        free(save);
    }
    return;
}

s_test *creatlistest(s_test *newlist)
{
    newlist = malloc(sizeof(s_test));
    newlist->good = -1;
    newlist->next = NULL;
    return (newlist);
}

s_test *addtestlist(s_test *testlist, int type)
{

    if (testlist->good == -1)
    {
        testlist->good = type;
    }
    else
    {
        s_test *tmp = testlist;
        s_test *newentries;
        newentries = malloc(sizeof(s_test));
        newentries->good = type;
        newentries->next = NULL;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newentries;
    }
    return (testlist);
}
int teststate(int state, s_test *list)
{
    int cr = 0;
    s_test *tmp = list;
    while (tmp != NULL)
    {
        if (state == tmp->good)
        {
            cr = 1;
        }
        tmp = tmp->next;
    }
    //   printf("test teststate cr %d\n", cr);
    return (cr);
}

int goodcell(s_maap *unitepos, s_maap *targetpos)
{
    s_maap *lastpos = unitepos;
    while (lastpos->next != NULL)
    {
        lastpos = lastpos->next;
    }
    int cr = 1;
    int testX = unitepos->X - targetpos->X;
    int testY = unitepos->Y - targetpos->Y;
    int testcase = unitepos->X + unitepos->Y - targetpos->X - targetpos->Y;
    if (targetpos->X < 0 || targetpos->Y < 0 || targetpos->Y > lastpos->Y || targetpos->X > lastpos->X || testcase > 2 || testcase < -2 || testX < -1 || testX > 1 || testY < -1 || testY > 1)
    {
        cr = 0;
    }
    printf("test goodcell cr %d\n", cr);
    return (cr);
}

int footcell(s_maap *unitepos, s_maap *targetpos)
{
    int cr = 0;
    int testX = unitepos->X - targetpos->X;
    int testY = unitepos->Y - targetpos->Y;
    if (testX == 0 && testY == 0)
    {
        cr = 1;
    }
    //  printf("test footcell cr %d\n", cr);
    return (cr);
}

int isitmine(s_unit *myunite, s_unit *targetuinit)
{
    int cr = 0;
    if (myunite->owner == targetuinit->owner)
    {
        cr = 1;
    }
    //    printf("test isitmine cr %d\n", cr);
    return (cr);
}
int isfoodhere(int cellfoodstock)
{
    int cr = 0;

    if (cellfoodstock > 0)
    {
        cr = 1;
    }
    //  printf("test is food here cr %d\n", cr);
    return (cr);
}
int foodenough(int foodstock, int type, char *name)
{
    int cr = 1;
    if ((name[0] == 'b' && foodstock < 1) || ((type == 3 || type == 7) && foodstock < costbuilder) || ((type == 4 || type == 8) && foodstock < costsoldier) || ((type == 6 || type == 10) && foodstock < costruche))
    {
        cr = 0;
    }
    // printf("test foodenough cr %d\n", cr);
    return (cr);
}
int foodstock(s_unit *unit)
{
    int cr = 1;
    if ((unit->unitname[0] == 'b' && unit->stock_food >= limitfood) || (unit->unitname[0] == 'r' && unit->stock_food >= limitstockfood))
    {
        cr = 0;
    }
    //    printf("foodstock test cr %d\n", cr);
    return (cr);
}
