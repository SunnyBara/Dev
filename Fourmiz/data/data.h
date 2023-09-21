#ifndef data_h
#define data_h

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
typedef struct pheromone
{
    int ruche1;
    int gotfood1;
    int fight1;
    int ruche2;
    int gotfood2;
    int fight2;

} s_phero;
typedef struct maap
{
    int X;
    int Y;
    struct maap *next;
    int state;
    s_phero *phero;
    int food;
} s_maap;
typedef struct unit
{
    int X;
    int Y;
    int owner;
    char *unitname;
    int stock_food;
    int health;
    struct unit *next;
} s_unit;
typedef struct army
{
    int owner;
    s_unit *firstunit;
    struct army *next;
} s_army;
typedef struct test
{
    int good;
    struct test *next;
} s_test;

typedef struct move
{
    s_unit *unit;
    int cX;
    int cY;
    int action;

} s_action;
typedef struct packagethread
{
    s_maap *maap;
    s_army *armylist;
} s_pack;

s_maap *find(int cX, int cY, s_maap *maap);
s_unit *findunit(int cX, int cY, s_army *armylist);
#endif