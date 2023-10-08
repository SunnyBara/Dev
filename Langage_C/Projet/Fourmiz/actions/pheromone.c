#include "../data/data.h"
#include "test.h"

int testdropphero(s_unit *unite, int cX, int cY, s_maap *maap)
{
    int cr;
    s_maap *maapcell;
    s_maap *unitecell;
    unitecell = find(unite->X, unite->Y, maap);
    maapcell = find(cX, cY, maap);
    s_test *forteststate = creatlistest(forteststate);
    forteststate = addtestlist(forteststate, 4);
    forteststate = addtestlist(forteststate, 3);
    forteststate = addtestlist(forteststate, 7);
    forteststate = addtestlist(forteststate, 8);
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
void dropphero(s_unit *unite, int cX, int cY, s_maap *maap, int pherotype)
{
    s_maap *thismaap = find(cX, cY, maap);
    if (unite->owner == 1)
    {
        if (pherotype == 0)
        {
            thismaap->phero->ruche1 += 1;
        }
        else if (unite->unitname[0] == 'b')
        {
            printf("builder 1 phero\n");
            thismaap->phero->gotfood1 += 1;
            printf(" phero on maap %d \n", thismaap->phero->gotfood1);
        }
        else if (unite->unitname[0] == 's')
        {
            thismaap->phero->fight1 += 1;
        }
    }
    else if (unite->owner == 2)
    {
        printf("unite 2 phero\n");
        if (pherotype == 0)
        {
            thismaap->phero->ruche2 += 1;
        }
        else if (unite->unitname[0] == 'b')
        {

            thismaap->phero->gotfood2 += 1;
        }
        else if (unite->unitname[0] == 's')
        {
            thismaap->phero->fight2 += 1;
        }
    }
    return;
}
