#include "./data/data.h"

//fonctions testés:

//Filegestion/files.c
s_maap* loadfile(s_maap *maap);

//game/sonar.c
s_maap *sonar(int cX, int cY, s_maap *maap);

//game/army.c
void add(s_unit *newunit, s_unit *army);
s_army *buildarmy(s_maap *maap);
void isdead(s_unit *unitdead, s_maap *targetcell, s_army *armylist);
void isitdead(s_unit *unitdamaged, s_maap *targetcell,s_army *armylist);

//game/print.c
int loadgame(int argc, char **argv, s_maap *maap, int line, int column,s_army *list);


//actions/createunite.c
void create_unit(s_unit *army, int type, int cX, int cY,s_maap *maap);
int testcreateunite(s_unit *unite, int type, int cX, int cY, s_maap *maap);

//actions/attack.c
void attack(s_unit *unite, int cX, int cY, s_maap *maap, s_army *armylist);
int testattack(s_unit *unite, int cX, int cY, s_maap *maap, s_army *armylist);


//actions/move.c
void move(s_unit *unite, int cX, int cY, s_maap *maap);
int testmove(s_unit *unite, int cX, int cY, s_maap *maap);

//actions/managefood.c
int testdropfood(s_unit *unite, int cX, int cY, s_maap *maap, s_army *armylist);
int testpickfood(s_unit *unite, int cX, int cY, s_maap *maap);
int pickfood(s_unit *unite, int cX, int cY, s_maap *maap);
void dropfood(s_unit *unite, int cX, int cY, s_maap *maap, s_army *armylist);

//actions/pheromone.c
int testdropphero(s_unit *unite, int cX, int cY, s_maap *maap);
void dropphero(s_unit *unite, int cX, int cY, s_maap *maap);

//actions/test.c
s_test *creatlistest(s_test *newlist);
s_test *addtestlist(s_test *testlist, int type);
void freetest(s_test *list);
int goodcell(s_maap *unitepos, s_maap *targetpos);
int footcell(s_maap *unitepos, s_maap *targetpos);
int teststate(int state, s_test *list);
int isitmine(s_unit *myunite, s_unit *targetuinit);
int isfoodhere(int cellfoodstock);
int foodenough(int foodstock, int type);
int foodstock(s_unit *unit);

//data/data.c
s_maap *find(int cX, int cY, s_maap *maap);
s_unit *findunit(int cX, int cY, s_army *armylist);


//A tester :

