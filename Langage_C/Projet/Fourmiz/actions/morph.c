#include "../data/data.h"
#include "test.h"

int testmorph(s_unit *unite, int cX, int cY, s_maap *maap)
{

    int cr;
    s_maap *maapcell;
    s_maap *unitecell;
    unitecell = find(unite->X, unite->Y, maap);
    maapcell = find(cX, cY, maap);
    s_test *forteststate = creatlistest(forteststate);
    forteststate = addtestlist(forteststate, 6);
    forteststate = addtestlist(forteststate, 10);
    if ((teststate(unitecell->state, forteststate)) && (footcell(unitecell, maapcell)))
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

void morph(s_unit *unite, int cX, int cY, s_maap *maap)
{
    s_maap *tmp;
    int save;
    tmp = find(unite->X, unite->Y, maap);
    if (tmp->state == 6)
    {
        tmp->state = 5;
    }
    else if (tmp->state == 10) 
    {
        tmp->state = 9;
    }
    unite->unitname = "ruche";
    return;
}