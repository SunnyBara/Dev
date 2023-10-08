#include "data.h"
s_maap *find(int cX, int cY, s_maap *maap)
{
    s_maap *tmp;
    tmp = maap;
    while ( tmp->next != NULL &&(tmp->X != cX || tmp->Y != cY))
    {
        tmp = tmp->next;
    }
    return (tmp);
}
s_unit *findunit(int cX, int cY, s_army *armylist)
{
    s_army  *tmparmy=armylist;
    s_unit *tmpunit = tmparmy->firstunit;
    while(tmparmy != NULL)
    {
        while(tmpunit != NULL && (tmpunit->X != cX || tmpunit->Y != cY))
        {
            tmpunit=tmpunit->next;
        }
        tmparmy = tmparmy->next;
        if(tmpunit ==NULL && tmparmy != NULL)
        {
            tmpunit = tmparmy->firstunit;
        }
    }
    return(tmpunit);
}