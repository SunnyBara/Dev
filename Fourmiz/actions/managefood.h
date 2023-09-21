#include "../data/data.h"
#ifndef food_h
#define food_h
int testdropfood(s_unit *unite, int cX, int cY, s_maap *maap, s_army *armylist);
int testpickfood(s_unit *unite, int cX, int cY, s_maap *maap);
int pickfood(s_unit *unite, int cX, int cY, s_maap *maap);
void dropfood(s_unit *unite, int cX, int cY, s_maap *maap, s_army *armylist);
#endif