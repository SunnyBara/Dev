#ifndef game_h
#define game_h
//cost on unite creation
#define  costbuilder  5
#define  costsoldier  10
#define  costruche  100
// foodstock at the begining
#define  startingfoodstock
//initial food on unit "ruche"
#define  stockcreateruchestock
// initial food amount on the cell 
#define  initialfood 10
//limit of food amount carry by builder
#define  limitfood 5
//limit of food stock in a ruche
#define  limitstockfood 1500
void *tourdejeu(void *arg);
void slowgame(float slowfactor);
#endif