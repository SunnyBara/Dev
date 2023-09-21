#include "../data/data.h"

s_action *letsdropphero2(s_unit *unit)
{
    s_action *act;
    act = malloc(sizeof(s_action));
    act->action = 6;
    act->cX = unit->X;
    act->cY = unit->Y;
    return (act);
}

s_action *letsmove2(s_unit *unit)
{
    s_action *act;
    act = malloc(sizeof(s_action));
    act->action = 0;
    act->cX = unit->X + 1;
    act->cY = unit->Y;
    return (act);
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
    act->action = pass;
    s_maap *mypos = aroundunit;
    while (mypos->X != unit->X && mypos->Y != unit->Y)
    {
        mypos = mypos->next;
    }
    if (unit->unitname[0] == 's')
    {
        if (unit->X == 0)
        {
            act = letsmove2(unit);
        }
        else if (unit->X == 1 && mypos->phero->fight2 < 24)
        {
            act = letsdropphero2(unit);
        }
        else if (unit->X == 1 && mypos->phero->fight2 >= 24 && mypos->phero->fight2 < 50)
        {
            act = letsmove2(unit);
        }
        else if (unit->X == 2 && mypos->phero->fight2 < 49)
        {
            act = letsdropphero2(unit);
        }
        else if (unit->X == 2 && mypos->phero->fight2 >= 49 && mypos->phero->fight2 < 74)
        {
            act = letsmove2(unit);
        }
        else if (unit->X == 3 && mypos->phero->fight2 < 74)
        {
            act = letsdropphero2(unit);
        }
        else if (unit->X == 3 && mypos->phero->fight2 >= 74)
        {
            act = letsmove2(unit);
        }
        else if (unit->X == 4 && mypos->phero->fight2 < 99)
        {
            act = letsdropphero2(unit);
        }
        else if (unit->X == 4 && mypos->phero->fight2 >= 99)
        {
            act = letsmove2(unit);
        }
        else if (unit->X == 5 && mypos->phero->fight2 < 102)
        {
            act = letsdropphero2(unit);
        }
        else if (unit->X == 5 && mypos->phero->fight2 >= 102)
        {
            act = letsmove2(unit);
        }
    }
    else if (unit->unitname[0] == 'b')
    {
        if (unit->X == 0)
        {
            act = letsmove2(unit);
        }
        else if (unit->X == 1 && mypos->phero->gotfood2 < 24)
        {
            act = letsdropphero2(unit);
        }
        else if (unit->X == 1 && mypos->phero->gotfood2 >= 24 && mypos->phero->gotfood2 < 50)
        {
            act = letsmove2(unit);
        }
        else if (unit->X == 2 && mypos->phero->gotfood2 < 49)
        {
            act = letsdropphero2(unit);
        }
        else if (unit->X == 2 && mypos->phero->gotfood2 >= 49 && mypos->phero->gotfood2 < 74)
        {
            act = letsmove2(unit);
        }
        else if (unit->X == 3 && mypos->phero->gotfood2 < 74)
        {
            act = letsdropphero2(unit);
        }
        else if (unit->X == 3 && mypos->phero->gotfood2 >= 74)
        {
            act = letsmove2(unit);
        }
        else if (unit->X == 4 && mypos->phero->gotfood2 < 99)
        {
            act = letsdropphero2(unit);
        }
        else if (unit->X == 4 && mypos->phero->gotfood2 >= 99)
        {
            act = letsmove2(unit);
        }
        else if (unit->X == 5 && mypos->phero->gotfood2 < 102)
        {
            act = letsdropphero2(unit);
        }
        else if (unit->X == 5 && mypos->phero->gotfood2 >= 102)
        {
            act = letsmove2(unit);
        }
    }
    else if (unit->unitname[0] == 'r')
    {
    }
    else if (unit->unitname[0] == 'q')
    {
    }

    act->unit = unit;
    return (act);
}