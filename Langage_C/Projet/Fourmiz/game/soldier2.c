#include "../data/data.h"

s_maap *findtarget(s_unit *unit, s_maap *aroundunit)
{
    s_maap *tmp = aroundunit;
    while (tmp != NULL && tmp->state != 5)
    {
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        printf("null\n");
    }
    return (tmp);
}

s_action *askaction2(s_unit *unit, s_maap *aroundunit)
{
    s_action *act;
    act = malloc(sizeof(s_action));
    int move = 0;
    int attack = 1;
    int create_builder = 2;
    int create_soldier = 3;
    int create_queen = 4;
    int droppheroruche = 5;
    int dropspecialphero = 6;
    int pickfood = 7;
    int dropfood = 8;
    int morphqueen = 9;
    int pass = 10;
    act->unit = unit;
    s_maap *target;
    if (unit->unitname[0] == 's')
    {
        printf("soldier\n");
        target = findtarget(unit, aroundunit);
        act->action = attack;
        act->cX = target->X;
        act->cY = target->Y;
    }
    else
    {
        act->action = pass;
        act->cX = unit->X;
        act->cY = unit->Y;
    }

    return (act);
}