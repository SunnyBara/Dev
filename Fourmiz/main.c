#include "./data/data.h"
#include "./Filesgestion/files.h"
#include "./game/Allgame.h"
#include "./actions/allaction.h"

s_maap *createmaap(s_maap *maap)
{
    s_phero *phero;
    phero = malloc(sizeof(s_phero));
    phero->ruche1 = 0;
    phero->ruche2 = 0;
    phero->gotfood1 = 0;
    phero->gotfood2 = 0;
    phero->fight1 = 0;
    phero->fight2 = 0;
    maap = malloc(sizeof(s_maap));
    maap->food = 0;
    maap->X = 0;
    maap->Y = 0;
    maap->phero = phero;
    maap->state = 0;
    maap->next = NULL;
}

int main(int argc, char **argv)
{
    s_maap *maap;
    maap = createmaap(maap);
    maap = loadfile(maap);
    s_army *armylist;
    armylist = malloc(sizeof(s_army));
    printf("buildarmy\n");
    armylist = buildarmy(maap);
    s_maap *tmp = maap;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    loadgame(argc, argv, maap, tmp->X + 1, tmp->Y + 1, armylist);
    return (0);
}