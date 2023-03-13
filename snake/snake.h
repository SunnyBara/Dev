#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
typedef struct state
{
    char *state;
} s_state;

typedef struct temps
{
    int h;
    int min;
    int s;
    int ns;
} s_temps;

typedef struct element
{
    int x;
    int y;
    int prev_x;
    int prev_y;
    struct element *next;
}s_elem;

typedef struct foodlist
{
    s_elem *lfood;
    struct foodlist *next;
}s_foodlist;

typedef struct Snakecorps
{
    s_elem *head;
}s_Snakecorps;