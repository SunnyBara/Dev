
#include "../data/data.h"
#include "test.h"
#include "../game/army.h"

int testpickfood(s_unit *unite, int cX, int cY, s_maap *maap)
{

    int cr;
    s_maap *maapcell;
    s_maap *unitecell;
    unitecell = find(unite->X, unite->Y, maap);
    maapcell = find(cX, cY, maap);
    s_test *forteststate = creatlistest(forteststate);
    forteststate = addtestlist(forteststate, 3);
    forteststate = addtestlist(forteststate, 7);
    if ((isfoodhere(maapcell->food)) && (teststate(unitecell->state, forteststate)) && (footcell(unitecell, maapcell) && (foodstock(unite))))
    {
        cr = 1;
    }
    else
    {
        cr = 0;
    }
    freetest(forteststate);
    return (cr);
}

int testdropfood(s_unit *unite, int cX, int cY, s_maap *maap, s_army *armylist)
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
    fortestcase = addtestlist(fortestcase, 5);
    fortestcase = addtestlist(fortestcase, 9);
    s_test *forteststate = creatlistest(forteststate);
    forteststate = addtestlist(forteststate, 3);
    forteststate = addtestlist(forteststate, 7);
    if ((teststate(maapcell->state, fortestcase)) && (teststate(unitecell->state, forteststate)) && (goodcell(unitecell, maapcell) && (isitmine(unite, targetunit)) && (foodstock(targetunit) && (foodenough(unite->stock_food, 1,unite->unitname)))))
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

void pickfood(s_unit *unite, int cX, int cY, s_maap *maap)
{

    unite->stock_food = unite->stock_food + 1;
    s_maap *maapcell = find(cX, cY, maap);
    maapcell->food = maapcell->food - 1;
    return;
}

void dropfood(s_unit *unite, int cX, int cY, s_maap *maap, s_army *armylist)
{
    s_unit *ruche;
    ruche = findunit(cX, cY, armylist);
    printf("food in ruche before drop  %d\n", ruche->stock_food);
    unite->stock_food = unite->stock_food - 1;
    ruche->stock_food = ruche->stock_food + 1;
    printf("food in ruche after drop  %d\n", ruche->stock_food);
    return;
}
