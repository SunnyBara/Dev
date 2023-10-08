#include "../data/data.h"
#include "../game/army.h"
#include "test.h"

int testcreateunite(s_unit *unite, int type, int cX, int cY, s_maap *maap)
{
    printf("testcreateunit\n");
    int cr;
    s_maap *maapcell;
    s_maap *unitecell;
    unitecell = find(unite->X, unite->Y, maap);
    maapcell = find(cX, cY, maap);
    s_test *fortestcase;
    fortestcase = creatlistest(fortestcase);
    fortestcase = addtestlist(fortestcase, 0);
    s_test *forteststate = creatlistest(forteststate);
    forteststate = addtestlist(forteststate, 5);
    forteststate = addtestlist(forteststate, 9);
    s_test *fortestcreate = creatlistest(fortestcreate);
    fortestcreate = addtestlist(fortestcreate, 3);
    fortestcreate = addtestlist(fortestcreate, 4);
    fortestcreate = addtestlist(fortestcreate, 5);
    fortestcreate = addtestlist(fortestcreate, 6);
    fortestcreate = addtestlist(fortestcreate, 7);
    fortestcreate = addtestlist(fortestcreate, 8);
    fortestcreate = addtestlist(fortestcreate, 9);
    fortestcreate = addtestlist(fortestcreate, 10);
    if ((teststate(maapcell->state, fortestcase)) && (teststate(unitecell->state, forteststate)) && (teststate(type, fortestcreate)) && (goodcell(unitecell, maapcell)) && foodenough(unite->stock_food, type,unite->unitname))
    {
        cr = 1;
    }
    else
    {
        cr = 0;
    }
    printf("freetest\n");
    freetest(fortestcase);
    freetest(forteststate);
    freetest(fortestcreate);
    return (cr);
}

s_unit *createbuilder(s_unit *newbuilder)
{
    newbuilder->health = 40;
    newbuilder->unitname = "builder";
    return (newbuilder);
}
s_unit *createsoldier(s_unit *newsoldier)
{
    newsoldier->health = 60;
    newsoldier->unitname = "soldier";
    return (newsoldier);
}
s_unit *createruche(s_unit *newruche)
{
    newruche->health = 3000;
    newruche->unitname = "ruche";
    newruche->stock_food = 100;
    return (newruche);
}
s_unit *createqueen(s_unit *newqueen)
{
    newqueen->health = 3000;
    newqueen->unitname = "queen";
    newqueen->stock_food = 100;
    return (newqueen);
}
void create_unit(s_unit *army, int type, int cX, int cY, s_maap *maap)
{
    s_maap *tmp;
    tmp = find(cX, cY, maap);
    s_unit *newunit;
    newunit = malloc(sizeof(s_unit));
    newunit->X = cX;
    newunit->Y = cY;
    newunit->next = NULL;
    if (type == 3 || type == 7)
    {
        newunit = createbuilder(newunit);
    }
    else if (type == 4 || type == 8)
    {
        newunit = createsoldier(newunit);
    }
    else if (type == 5 || type == 9)
    {
        newunit = createruche(newunit);
    }
    else if (type == 6 || type == 10)
    {
        newunit = createqueen(newunit);
    }
    newunit->owner = army->owner;
    add(newunit, army);
    tmp->state = type;
    return;
}
