#include "../data/data.h"
#include "test.h"

int testmove(s_unit *unite, int cX, int cY, s_maap *maap)
{
    int cr;
    s_maap *maapcell;
    s_maap *unitecell;
    unitecell = find(unite->X, unite->Y, maap);
    maapcell = find(cX, cY, maap);
    s_test *fortestcase;
    fortestcase = creatlistest(fortestcase);
    fortestcase = addtestlist(fortestcase, 0);
    s_test *forteststate = creatlistest(forteststate);
    forteststate = addtestlist(forteststate, 4);
    forteststate = addtestlist(forteststate, 3);
    forteststate = addtestlist(forteststate, 6);
    forteststate = addtestlist(forteststate, 7);
    forteststate = addtestlist(forteststate, 8);
    forteststate = addtestlist(forteststate, 10);
    if (((goodcell(unitecell, maapcell) && teststate(maapcell->state, fortestcase)) && (teststate(unitecell->state, forteststate))))
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

void move(s_unit *unite, int cX, int cY, s_maap *maap)
{
    s_maap *tmp;
    int save;
    tmp = find(unite->X, unite->Y, maap);
    save = tmp->state;
    tmp->state = 0;
    tmp = find(cX, cY, maap);
    tmp->state = save;
    unite->X = cX;
    unite->Y = cY;
    return;
}