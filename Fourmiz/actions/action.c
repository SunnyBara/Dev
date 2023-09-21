#include "../data/data.h"
#include "../game/Allgame.h"
#include "allaction.h"

void action(int action, s_unit *unit, int cX, int cY, s_maap *maap, s_army *armylist, s_unit *ennemiunit)
{

    if (action == 0 && testmove(unit, cX, cY, maap))
    {
        move(unit, cX, cY, maap);
    }
    else if (action == 1 && testattack(unit, cX, cY, maap, armylist))
    {
        s_unit *targetunit;
        targetunit = attack(unit, cX, cY, maap, armylist);
        isitdead(targetunit, find(cX, cY, maap), armylist, ennemiunit);
    }
    else if (action == 2 && testcreateunite(unit, 2, cX, cY, maap))
    {
        create_unit(unit, 2, cX, cY, maap);
        unit->stock_food = unit->stock_food - costbuilder;
    }
    else if (action == 3 && testcreateunite(unit, 3, cX, cY, maap))
    {
        create_unit(unit, 3, cX, cY, maap);
        unit->stock_food = unit->stock_food - costsoldier;
    }
    else if (action == 4 && testcreateunite(unit, 4, cX, cY, maap))
    {
        create_unit(unit, 5, cX, cY, maap);
        unit->stock_food = unit->stock_food - costruche;
    }
    else if (action == 5 && testdropphero(unit, cX, cY, maap))
    {
        dropphero(unit, cX, cY, maap, 0);
    }
    else if (action == 6 && testdropphero(unit, cX, cY, maap))
    {
        dropphero(unit, cX, cY, maap, 1);
    }
    else if (action == 7 && testpickfood(unit, cX, cY, maap))
    {
        pickfood(unit, cX, cY, maap);
    }
    else if (action == 8 && testdropfood(unit, cX, cY, maap, armylist))
    {
        dropfood(unit, cX, cY, maap, armylist);
    }
    else if (action == 9 && testmorph(unit, cX, cY, maap))
    {
        morph(unit, cX, cY, maap);
    }
    else
    {
    }
    return;
}