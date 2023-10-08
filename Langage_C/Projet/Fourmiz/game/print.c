#include <../GL/gl.h>
#include <../GL/glu.h>
#include <../GL/glut.h>
#include <../GL/freeglut.h>
#include "../data/data.h"
#include "Allgame.h"

// angle of rotation for the camera direction
double angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f;
float z = 0.0f;
float y = 36.0f;
s_maap *loadmaap;
s_army *armylist;
int X;
int Y;
char showt1 = 'N';
char showt2 = 'N';
float speedrate = 1.0;

/*void checkchronos(void)
{
    int subs;
    int submin;
    int subhour;
    time(&star);
    loca = localtime(&star);
    subs = loca->tm_sec - start->s;
    submin = loca->tm_min - start->min;
    subhour = loca->tm_hour - start->h;
    return;
}*/

float setupgradient(int pherostack)
{
    float gradient = 1.0f;
    if (pherostack >= 25 && pherostack < 50)
    {
        gradient = 0.9f;
    }
    else if (pherostack >= 50 && pherostack < 75)
    {
        gradient = 0.8f;
    }

    else if (pherostack >= 75)
    {
        gradient = 0.7f;
    }
    return (gradient);
}

void split3j1(s_maap *tmp, float gradientbuilder, float gradientsoldier, float gradientruche)
{
    glColor4f(1.0f, gradientbuilder, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 3.3);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 3.3);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
    glEnd();
    glColor3f(1.0f, 0.0f, gradientsoldier);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 6.6);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 6.6);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 3.3);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 3.3);
    glEnd();
    glColor4f(1.0f, 1.0f, gradientruche, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 6.6);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 6.6);
    glEnd();
    return;
}
void split3j2(s_maap *tmp, float gradientbuilder, float gradientsoldier, float gradientruche)
{
    glColor4f(0.0f, gradientbuilder, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 3.3);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 3.3);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
    glEnd();
    glColor4f(0.0f, gradientsoldier - 0.4f, gradientsoldier - 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 6.6);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 6.6);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 3.3);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 3.3);
    glEnd();
    glColor4f(0.0f, 1.0f, gradientruche, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 6.6);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 6.6);
    glEnd();
    return;
}

void split21j1(s_maap *tmp, float gradientbuilder, float gradientsoldier)
{
    glColor4f(1.0f, gradientbuilder, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
    glEnd();
    glColor3f(1.0f, 0.0f, gradientsoldier);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glEnd();
    return;
}
void split22j1(s_maap *tmp, float gradientbuilder, float gradientruche)
{
    glColor4f(1.0f, gradientbuilder, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
    glEnd();
    glColor4f(1.0f, 1.0f, gradientruche, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glEnd();
    return;
}
void split23j1(s_maap *tmp, float gradientsoldier, float gradientruche)
{
    glColor3f(1.0f, 0.0f, gradientsoldier);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
    glEnd();
    glColor4f(1.0f, 1.0f, gradientruche, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glEnd();
    return;
}
void split21j2(s_maap *tmp, float gradientbuilder, float gradientsoldier)
{
    glColor4f(0.0f, gradientbuilder, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
    glEnd();
    glColor4f(0.0f, gradientsoldier - 0.4f, gradientsoldier - 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glEnd();
    return;
}
void split322j2(s_maap *tmp, float gradientbuilder, float gradientruche)
{
    glColor4f(0.0f, gradientbuilder, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
    glEnd();
    glColor4f(0.0f, 1.0f, gradientruche, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glEnd();
    return;
}
void split23j2(s_maap *tmp, float gradientsoldier, float gradientruche)
{
    glColor4f(0.0f, gradientsoldier - 0.4f, gradientsoldier - 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
    glEnd();
    glColor4f(0.0f, 1.0f, gradientruche, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
    glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 5);
    glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 5);
    glEnd();
    return;
}

void drawgame(void)
{

    int SIZE = 100;
    int i = 0;

    // draw table;
    while (i <= X * 10)
    {
        glColor3f(1.0f, 0.5f, 0.5f);
        glBegin(GL_LINES);
        glVertex3f(0, 0, i);
        glVertex3f(Y * 10, 0, i);
        glEnd();
        i = i + 10;
    }
    i = 0;
    while (i <= Y * 10)
    {
        glBegin(GL_LINES);
        glVertex3f(i, 0, 0);
        glVertex3f(i, 0, X * 10);
        glEnd();
        i = i + 10;
    }
    // Draw cell
    s_maap *tmp = loadmaap;
    while (tmp != NULL)
    {

        if (tmp->state == 1)
        {
            glColor4f(0.5f, 0.5f, 0.5f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
        }
        // Unite J1
        else if (tmp->state == 3)
        {
            glColor3f(1.0f, 0.65f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
        }
        else if (tmp->state == 4)
        {
            glColor3f(1.0f, 0.45f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
        }
        else if (tmp->state == 5)
        {
            glColor3f(0.75f, 0.0f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
        }
        else if (tmp->state == 6)
        {
            glColor3f(1.0f, 0.0f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
        }
        // Unite J2
        else if (tmp->state == 7)
        {
            glColor3f(0.0f, 0.4f, 1.0f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
        }
        else if (tmp->state == 8)
        {
            glColor3f(0.0f, 0.1f, 0.6f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
        }
        else if (tmp->state == 9)
        {
            glColor3f(0.0f, 0.5f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
        }
        else if (tmp->state == 10)
        {
            glColor4f(0.0f, 0.75f, 0.0f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
        }
        if (tmp->food != 0)
        {
            glColor4f(0.75f, 0.5f, 0.25f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
        }
        float gradientbuilder1 = setupgradient(tmp->phero->gotfood1);
        float gradientsoldier1 = setupgradient(tmp->phero->fight1);
        float gradientruche1 = setupgradient(tmp->phero->ruche1);
        float gradientbuilder2 = setupgradient(tmp->phero->gotfood2);
        float gradientsoldier2 = setupgradient(tmp->phero->fight2);
        float gradientruche2 = setupgradient(tmp->phero->ruche2);
        if (showt1 == 'Y')
        {
            if (tmp->phero->gotfood1 > 0 && tmp->phero->fight1 > 0 && tmp->phero->ruche1 > 0)
            {

                split3j1(tmp, gradientbuilder1, gradientsoldier1, gradientruche1);
            }
            else if (tmp->phero->gotfood1 > 0 && tmp->phero->fight1 > 0)
            {
                split21j1(tmp, gradientbuilder1, gradientsoldier1);
            }
            else if (tmp->phero->gotfood1 > 0 && tmp->phero->ruche1 > 0)
            {
                split22j1(tmp, gradientbuilder1, gradientruche1);
            }
            else if (tmp->phero->ruche1 > 0 && tmp->phero->fight1 > 0)
            {
                split22j1(tmp, gradientsoldier1, gradientruche1);
            }
            else if (tmp->phero->gotfood1 > 0)
            {
                glColor4f(1.0f, gradientbuilder1, 0.0f, 0.0f);
                glBegin(GL_QUADS);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
                glEnd();
            }
            else if (tmp->phero->fight1 > 0)
            {
                glColor4f(1.0f, 0.0f, gradientsoldier1, 0.0f);
                glBegin(GL_QUADS);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
                glEnd();
            }
            else if (tmp->phero->ruche1 > 0)
            {
                glColor4f(1.0f, 1.0f, gradientruche1, 0.0f);
                glBegin(GL_QUADS);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
                glEnd();
            }
        }
        if (showt2 == 'Y')
        {
            if (tmp->phero->gotfood2 > 0 && tmp->phero->fight2 > 0 && tmp->phero->ruche2 > 0)
            {

                split3j1(tmp, gradientbuilder1, gradientsoldier1, gradientruche1);
            }
            else if (tmp->phero->gotfood2 > 0 && tmp->phero->fight2 > 0)
            {
                split21j1(tmp, gradientbuilder2, gradientsoldier2);
            }
            else if (tmp->phero->gotfood2 > 0 && tmp->phero->ruche2 > 0)
            {
                split22j1(tmp, gradientbuilder2, gradientruche2);
            }
            else if (tmp->phero->ruche2 > 0 && tmp->phero->fight2 > 0)
            {
                split22j1(tmp, gradientsoldier2, gradientruche2);
            }
            else if (tmp->phero->gotfood2 > 0)
            {
                glColor4f(0.0f, gradientbuilder2, 1.0f, 0.0f);
                glBegin(GL_QUADS);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
                glEnd();
            }
            else if (tmp->phero->fight2 > 0)
            {
                glColor4f(0.0f, gradientsoldier2 - 0.4f, gradientsoldier2 - 0.2f, 0.0f);
                glBegin(GL_QUADS);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
                glEnd();
            }
            else if (tmp->phero->ruche2 > 0)
            {
                glColor4f(0.0f, 1.0f, gradientruche2, 0.0f);
                glBegin(GL_QUADS);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
                glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
                glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
                glEnd();
            }
        }
        tmp = tmp->next;
    }
}

void displayf(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // Set the camera
    gluLookAt(x, y, z,
              x + lx, 1.0f, z + lz,
              0.0f, 1.0f, 0.0f);
    drawgame();
    glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int xi, int yi)
{
    switch (key)
    {
    case 'q':
        x += 1;
        break;

    case 'd':
        x -= 1;
        break;

    case 'z':
        z += 1;
        break;

    case 's':
        z -= 1;
        break;
    case 'r':
        if (showt1 == 'N')
        {
            showt1 = 'Y';
        }
        else
        {
            showt1 = 'N';
        }
        break;
    case 't':
        if (showt2 == 'N')
        {
            showt2 = 'Y';
        }
        else
        {
            showt2 = 'N';
        }
        break;
    case 'f':
        pthread_t gam;
        s_pack *argument;
        argument = malloc(sizeof(s_pack));
        argument->maap = loadmaap;
        argument->armylist = armylist;
        void *arg;
        arg = argument;
        pthread_create(&gam, NULL, tourdejeu, arg);
        break;
    case '+':
        speedrate = speedrate * 0.8;
        slowgame(speedrate);
        break;
    case '-':
        speedrate = speedrate * 1.2;
        slowgame(speedrate);

        break;
    }
}

void processSpecialKeys(int key, int xx, int yy)
{

    float fraction = 0.1f;

    switch (key)
    {
    case GLUT_KEY_UP:
        y -= 1;
        break;
    case GLUT_KEY_DOWN:
        y += 1;
        break;
    }
}

void reshape(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;
    float ratio = 1.0 * w / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45, ratio, 1, 1000);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}
void initialise(s_maap *maap, int line, int column, s_army *list)
{
    X = line;
    Y = column;
    y = 12 * X;
    x = 5 * X;
    z = 5 * X + 1;
    loadmaap = maap;
    armylist = list;
    return;
}

int loadgame(int argc, char **argv, s_maap *maap, int line, int column, s_army *list)
{
    initialise(maap, line, column, list);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(100, 100);
    int win = glutCreateWindow("Fourmiz");
    glutDisplayFunc(displayf);
    glutReshapeFunc(reshape);
    glutIdleFunc(displayf);
    glutSpecialFunc(processSpecialKeys);
    glutKeyboardFunc(processNormalKeys);
    // OpenGL init
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 1;
}