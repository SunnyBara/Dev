#include "data.h"
#include "game.h"
#include "print.h"
#include <stdio.h>
// angle of rotation for the camera direction
double angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 10.0f;
float z = 18.0f;
float y = 36.0f;
int X;
int Y;
s_cell *listcell;

//======================== Dossier Print.c===============================
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
    s_cell *tmp = listcell;
    while (tmp != NULL)
    {
        if (tmp->state == 1)
        {
            glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
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
    //   if (X != 0 && Y != 0)
    //   {
    drawgame();
    //   }

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
void processMouse(int button, int state, int a, int b)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
    {
        switch (state)
        {
        case GLUT_DOWN:
            printf("mouse x =%f mouse y = %f zoom = %f\n", x, z,y);
            break;
        }
    }
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

int printgame(int argc, char **argv, s_cell *list, int line, int column)
{
    X = line;
    Y = column;
    listcell = list;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(100, 100);
    int win = glutCreateWindow("Cell Game");
    glutDisplayFunc(displayf);
    glutReshapeFunc(reshape);
    glutIdleFunc(displayf);
    glutSpecialFunc(processSpecialKeys);
    glutKeyboardFunc(processNormalKeys);
    glutMouseFunc(processMouse);
    // OpenGL init
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 1;
}

//=========================dossier game.c =====================

void fillcell(int X, int Y, s_cell *listcell)
{
    s_cell *tmp;
    tmp = listcell;
    int i = 0;
    int j = 1;
    while (i < X)
    {

        while (j < Y)
        {
            s_cell *newcell;
            newcell = malloc(sizeof(s_cell));
            newcell->X = i;
            newcell->Y = j;
            if (i % 2 == 1)
            {
                newcell->state = 1;
            }
            else
            {
                newcell->state = 0;
            }
            tmp->next = newcell;
            tmp = tmp->next;
            j++;
        }
        i++;
        j = 0;
    }
}

//==================== dossier main ==============================
int main(int argc, char **argv)
{
    X = 3;
    Y = 2;
    listcell = malloc(sizeof(s_cell));
    fillcell(X, Y, listcell);
    printgame(argc, argv, listcell, X, Y);
    return 0;
}