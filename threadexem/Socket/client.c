#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <string.h>
typedef struct Serveurinfo
{
    char id;
    char action;
    int pos_x;
    int pos_y;
    char my_snake;
} s_servinf;

typedef struct etat
{
    char keystate;
    char *state;

} s_etat;

s_etat *etat;

// gestion du temps;
int reftime;
struct timespec now;
struct temps *tim;
struct temps *spawn;
struct temps *start;
struct tm *local;
struct tm *loca;
time_t star;

typedef struct temps
{
    int h;
    int min;
    int s;
    int ns;
} s_temps;

typedef struct food
{
	int x;
	int y;
} s_food;

s_food *food;

void startchronos(void)
{

    time(&star);
    loca = localtime(&star);
    start->h = loca->tm_hour;
    start->min = loca->tm_min;
    start->s = loca->tm_sec;
    return;
}
char checkchronos(void)
{
    int subs;
    int submin;
    int subhour;
    time(&star);
    loca = localtime(&star);
    subs = loca->tm_sec - start->s;
    submin = loca->tm_min - start->min;
    subhour = loca->tm_hour - start->h;
    return ('k');
}

s_servinf *inforecv;
int socketclient;

void *reception(void *arg)
{
    while (1)
    {
        recv(socketclient, inforecv, sizeof(s_servinf), 0);
        printf("inforecv %c\n",inforecv->id);
        if(inforecv->id == 'f')
        {
            if(food == NULL)
            {
                food = malloc(sizeof(s_food));
            }
            food->x = inforecv->pos_x;
            food->y = inforecv->pos_y;
            printf("foood x %i food y %i\n",food->x,food->y);
        }
    }
}

void displayf(void)
{
    timespec_get(&now, TIME_UTC);
    if (now.tv_sec >= tim->s + 1 || now.tv_nsec >= tim->ns + 50000000)
    {
        tim->s = now.tv_sec;
        tim->ns = now.tv_nsec;
        if (inforecv->id == '1')
        {
           // printf(" pos x %d pos y %d\n", inforecv->pos_x, inforecv->pos_y);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();
            gluLookAt(0, 0, 100,
                      0, 0, 0,
                      0.0f, 1.0f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f(-1 + inforecv->pos_x, 1 + inforecv->pos_y, 0);
            glVertex3f(1 + inforecv->pos_x, 1 + inforecv->pos_y, 0);
            glVertex3f(1 + inforecv->pos_x, -1 + inforecv->pos_y, 0);
            glVertex3f(-1 + inforecv->pos_x, -1 + inforecv->pos_y, 0);
            glEnd();
        }
        if (food != NULL)
        {
            // affichage food
            printf("affichage food\n");
            glBegin(GL_TRIANGLES);
            glVertex3f(-1 + food->x, -1 + food->y, 0);
            glVertex3f(-1 + food->x, 1 + food->y, 0);
            glVertex3f(1 + food->x, 1 + food->y, 0);
            glEnd();
        }
        glutSwapBuffers();
    }
}
void reshape(int a, int b)
{
    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);
    gluPerspective(80, 1, 10, 100);
    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}
void move(unsigned char key, int xi, int yi)
{
    if (key == 'q' && etat->state != "right")
    {
        etat->state = "left";
    }
    else if (key == 'd' && etat->state != "left")
    {
        etat->state = "right";
    }
    else if (key == 'z' && etat->state != "down")
    {
        etat->state = "up";
    }
    else if (key == 's' && etat->state != "up")
    {
        etat->state = "down";
    }
    else if (key == 'r')
    {
        etat->state = "reset";
    }
    else if (key == 'p')
    {
        etat->state = "pause";
    }
    send(socketclient, etat->state, 10, 0);
    glutDisplayFunc(displayf);
}

int main(int argc, char **argv)
{
    tim = malloc(sizeof(s_temps));
    tim->s = 0;
    tim->ns = 0;
    start = malloc(sizeof(s_temps));
    start->s = -1;
    start->ns = -1;

    etat = malloc(sizeof(s_etat));
    etat->state = malloc(7 * sizeof(char));

    inforecv = malloc(sizeof(s_servinf));

    // connection au  serveur.
    socketclient = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrserv;
    addrserv.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrserv.sin_family = AF_INET;
    addrserv.sin_port = htons(5465);
    memset(&(addrserv.sin_zero), '\0', 8);
    if (connect(socketclient, (struct sockaddr *)&addrserv, sizeof(struct sockaddr)))
    {
        perror("connect");
        exit(1);
    }

    pthread_t fill;
    pthread_create(&fill, NULL, reception, NULL);

    // INITIALIZATION
    glutInit(&argc, argv);
    // Size en pixels width * height
    glutInitWindowSize(400, 400);
    // Position x  y on the Window
    glutInitWindowPosition(750, 250);
    // Initial display mode
    glutInitDisplayMode(GLUT_RGBA);
    // Window Management
    int win = glutCreateWindow("my window ");
    glutDisplayFunc(displayf);
    glutReshapeFunc(reshape);
    glutIdleFunc(displayf);
    glutKeyboardFunc(move);
    printf("Loop\n");
    //	glutReshapeWindow(800,800);
    glutMainLoop();
    return EXIT_SUCCESS;
    return (0);
}