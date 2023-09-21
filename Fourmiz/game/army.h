#include "../data/data.h"
#ifndef army_h
#define army_h
void add(s_unit *newunit, s_unit *army);
s_army *buildarmy(s_maap *maap);
void isdead(s_unit *unitdead, s_maap *targetcell, s_army *armylist,s_unit *ennemiunit);
void isitdead(s_unit *unitdamaged, s_maap *targetcell,s_army *armylist,s_unit *ennemiunit);

#endif
