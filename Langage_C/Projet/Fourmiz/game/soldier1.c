#include "../data/data.h"

s_action *letsdropphero1(s_unit *unit)
{
    s_action *act;
    act = malloc(sizeof(s_action));
    act->action = 6;
    act->cX = unit->X;
    act->cY = unit->Y;
    return (act);
}

s_action *letsmove1(s_unit *unit)
{
    s_action *act;
    act = malloc(sizeof(s_action));
    act->action = 0;
    act->cX = unit->X + 1;
    act->cY = unit->Y;
    return (act);
}

s_action *askaction1(s_unit *unit, s_maap *aroundunit)
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
    act->action = pass;
    act->cX = unit->X;
    act->cY = unit->Y;
    act->unit = unit;
return (act);
}