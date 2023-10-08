#include "../data/data.h"
#include "../actions/createunit.h"
#include "../game/game.h"

void add(s_unit *newunit, s_unit *army)
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
        s_unit *tmp = army;
        while (tmp->next != NULL)
        {

            tmp = tmp->next;
        }
        tmp->next = newunit;
    }
    return;
}

s_army *buildarmy(s_maap *maap)
{
    s_unit *army1;
    s_unit *army2;
    army1 = malloc(sizeof(s_unit));
    army2 = malloc(sizeof(s_unit));
    army1->owner = 1;
    army2->owner = 2;
    army1->next = NULL;
    army2->next = NULL;

    s_army *newarmy;
    newarmy = malloc(sizeof(s_army));
    newarmy->firstunit = army2;
    newarmy->owner = 2;
    newarmy->next = NULL;

    s_army *armylist;
    armylist = malloc(sizeof(s_army));
    armylist->firstunit = army1;
    armylist->owner = 1;
    armylist->next = newarmy;

    s_maap *tmp;
    tmp = maap;
    while (tmp != NULL)
    {
        if (tmp->state > 2 && tmp->state < 11)
        {
            if (tmp->state > 2 && tmp->state < 7)
            {
                create_unit(army1, tmp->state, tmp->X, tmp->Y, maap);
            }
            else if (tmp->state > 6 && tmp->state < 11)
            {
                create_unit(army2, tmp->state, tmp->X, tmp->Y, maap);
            }
        }
        tmp = tmp->next;
    }
    return (armylist);
}

void isdead(s_unit *unitdead, s_maap *targetcell, s_army *armylist, s_unit *ennemiunit)
{
    char name = unitdead->unitname[0];
    s_army *goodarmy = armylist;
    while (goodarmy->owner != unitdead->owner)
    {
        goodarmy = goodarmy->next;
    }
    if (unitdead == goodarmy->firstunit)
    {
        goodarmy->firstunit = unitdead->next;
    }
    else
    {
        s_unit *previous = goodarmy->firstunit;
        while (previous->next != unitdead)
        {
            previous = previous->next;
        }
        previous->next = unitdead->next;
    }
    if (ennemiunit != NULL && ennemiunit == unitdead)
    {
        ennemiunit = ennemiunit->next;
    }
    free(unitdead);
    targetcell->state = 0;
    if (name == 'q' || name == 'r')
    {
        endgame(goodarmy);
    }
    return;
}

void isitdead(s_unit *unitdamaged, s_maap *targetcell, s_army *armylist, s_unit *ennemiunit)
{
    if (unitdamaged->health <= 0)
    {
        isdead(unitdamaged, targetcell, armylist, ennemiunit);
    }
    return;
}
