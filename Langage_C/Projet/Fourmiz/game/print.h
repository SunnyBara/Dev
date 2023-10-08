#include "../data/data.h"

#ifndef print_h
#define print_h					
typedef struct temps
{
    int h;
    int min;
    int s;
    int ns;
} s_temps;
int loadgame(int argc, char **argv, s_maap *maap, int line, int column,s_army *list);
void displayf(void);
#endif