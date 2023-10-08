#include "../data/data.h"
#include "test.h"
#include "../game/army.h"

int testattack(s_unit *unite, int cX, int cY, s_maap *maap, s_army *armylist)
{

    int cr;
    s_maap *maapcell;
    s_maap *unitecell;
    s_unit *targetunit;
    unitecell = find(unite->X, unite->Y, maap);
    maapcell = find(cX, cY, maap);
    targetunit = findunit(cX, cY, armylist);
    s_test *fortestcase;
    fortestcase = creatlistest(fortestcase);
    fortestcase = addtestlist(fortestcase, 6);
    fortestcase = addtestlist(fortestcase, 3);
    fortestcase = addtestlist(fortestcase, 4);
    fortestcase = addtestlist(fortestcase, 5);
    fortestcase = addtestlist(fortestcase, 7);
    fortestcase = addtestlist(fortestcase, 8);
    fortestcase = addtestlist(fortestcase, 9);
    fortestcase = addtestlist(fortestcase, 10);
    s_test *forteststate = creatlistest(forteststate);
    forteststate = addtestlist(forteststate, 4);
    forteststate = addtestlist(forteststate, 8);
    if ((teststate(maapcell->state, fortestcase)) && (teststate(unitecell->state, forteststate)) && (goodcell(unitecell, maapcell) && (!isitmine(unite, targetunit))))
    {
        cr = 1;
    }
    else
    {
        cr = 0;
    }
    freetest(fortestcase);
    freetest(forteststate);
    return (cr);
}

s_unit *attack(s_unit *unite, int cX, int cY, s_maap *maap, s_army *armylist)
{
    s_unit *targetunit = findunit(cX, cY, armylist);
    targetunit->health = targetunit->health - 20;
    return (targetunit);
}
