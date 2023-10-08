#include "../data/data.h"
#ifndef test_h
#define test_h
s_test *creatlistest(s_test *newlist);
s_test *addtestlist(s_test *testlist, int type);
void freetest(s_test *list);
int goodcell(s_maap *unitepos, s_maap *targetpos);
int footcell(s_maap *unitepos, s_maap *targetpos);
int teststate(int state, s_test *list);
int isitmine(s_unit *myunite, s_unit *targetuinit);
int isfoodhere(int cellfoodstock);
int foodenough(int foodstock, int type,char *name);
int foodstock(s_unit *unit);

#endif