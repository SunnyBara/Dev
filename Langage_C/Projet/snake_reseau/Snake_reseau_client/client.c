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
	int n;
} s_servinf;

typedef struct etat
{
	char keystate;
	char *state;

} s_etat;

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
	int n;
	char *state;
	char action;
	struct element *next;
} s_elem;
typedef struct food
{
	int x;
	int y;
} s_food;
typedef struct snakelist
{
	char id;
	struct element *snakehead;
	struct snakelist *next;
} s_snaklist;
typedef struct mysnak
{
	char id;
} s_mysnak;

//===================== Variables=========
// gestion du temps;
int reftime;
struct timespec now;
struct temps *tim;
struct temps *spawn;
struct temps *start;
struct tm *local;
struct tm *loca;
time_t star;

//==============Snake/food=======
s_food *food;
s_snaklist *list;
s_etat *etat;
s_mysnak *mysnake;
s_elem *snake;
s_servinf *inforecv;
int socketclient;
//===============Fonctions========
//================temps===========

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
//======Gestion du snake ============
s_snaklist *createsnake(void)
{
	s_snaklist *newclient;
	s_elem *snakehead;
	snakehead = malloc(sizeof(s_elem));
	snakehead->state = malloc(7 * sizeof(char));
	newclient = malloc(sizeof(s_snaklist));
	newclient->snakehead = snakehead;
	if (list == NULL)
	{
		list = malloc(sizeof(s_snaklist));
		list = newclient;
	}
	else
	{
		s_snaklist *tmp;
		tmp = list;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newclient;
	}
	return (newclient);
}
void resetsnake(s_snaklist *tmplist)
{
	s_elem *tmp;
	s_elem *save;
	tmp = tmplist->snakehead->next;
	tmplist->snakehead->next = NULL;
	while (tmp != NULL)
	{
		save = tmp;
		tmp = tmp->next;
		save->next = NULL;
	}
	tmplist->snakehead->x = 0;
	tmplist->snakehead->y = 0;
	return;
}

// =============Thread reception ================
void *reception(void *arg)
{
	while (1)
	{
		recv(socketclient, inforecv, sizeof(s_servinf), 0);
		if (inforecv->id == 'f')
		{
			if (food == NULL)
			{
				food = malloc(sizeof(s_food));
			}
			food->x = inforecv->pos_x;
			food->y = inforecv->pos_y;
		}
		else if (inforecv->id > 48 && inforecv->id < 57)
		{
			s_snaklist *tmplist;
			tmplist = list;
			while (tmplist != NULL && tmplist->id != inforecv->id)
			{
				tmplist = tmplist->next;
			}
			if (tmplist == NULL)
			{
				tmplist = createsnake();
				tmplist->id = inforecv->id;
			}
			s_elem *tmp;
			tmp = tmplist->snakehead;
			while (tmp->next != NULL)
			{
				tmp->prev_x = tmp->x;
				tmp->prev_y = tmp->y;
				tmp = tmp->next;
			}
			if (inforecv->action == 'H')
			{
				tmplist->snakehead->x = inforecv->pos_x;
				tmplist->snakehead->y = inforecv->pos_y;
			}
			else if (inforecv->action == 'C')
			{
				tmp = tmplist->snakehead;
				while (tmp->next != NULL && tmp->next->n != inforecv->n)
				{
					tmp = tmp->next;
				}
				if (tmp->next == NULL)
				{
					s_elem *corps;
					corps = malloc(sizeof(s_elem));
					corps->n = inforecv->n;
					corps->action = inforecv->action;
					tmp->next = corps;
				}
				tmp->next->x = inforecv->pos_x;
				tmp->next->y = inforecv->pos_y;
			}
			else if (inforecv->action == 'R')
			{
				resetsnake(tmplist);
			}
		}
	}
}
//=======Affichage==================
void displayf(void)
{
	timespec_get(&now, TIME_UTC);
	if (now.tv_sec >= tim->s + 1 || now.tv_nsec >= tim->ns + 5000000)
	{
		tim->s = now.tv_sec;
		tim->ns = now.tv_nsec;
		if (list != NULL)
		{
			s_snaklist *tmplist;
			tmplist = list;
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();
			gluLookAt(0, 0, 100,
					  0, 0, 0,
					  0.0f, 1.0f, 0.0f);

			while (tmplist != NULL)
			{
				glBegin(GL_QUADS);
				if (tmplist->id == mysnake->id)
				{
					glColor3f(0.0f, 1.0f, 0.0f);
				}
				else
				{
					glColor3f(11.0f, 1.0f, 0.0f);
				}
				glVertex3f(-1 + tmplist->snakehead->x, 1 + tmplist->snakehead->y, 0);
				glVertex3f(1 + tmplist->snakehead->x, 1 + tmplist->snakehead->y, 0);
				glVertex3f(1 + tmplist->snakehead->x, -1 + tmplist->snakehead->y, 0);
				glVertex3f(-1 + tmplist->snakehead->x, -1 + tmplist->snakehead->y, 0);
				glEnd();
				s_elem *tmp;
				tmp = tmplist->snakehead;
				while (tmp->next != NULL)
				{
					tmp->next->x = tmp->prev_x;
					tmp->next->y = tmp->prev_y;
					tmp = tmp->next;
					glBegin(GL_QUADS);
					glVertex3f(-0.75 + tmp->x, 0.75 + tmp->y - 1, 0);
					glVertex3f(0.75 + tmp->x, 0.75 + tmp->y - 1, 0);
					glVertex3f(0.75 + tmp->x, -0.75 + tmp->y - 1, 0);
					glVertex3f(-0.75 + tmp->x, -0.75 + tmp->y - 1, 0);
					glEnd();
				}
				tmplist = tmplist->next;
			}
		}
		if (food != NULL)
		{
			// affichage food
			glColor3f(11.0f, 1.0f, 1.0f);
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
	glMatrixMode(GL_PROJECTION);
	gluPerspective(80, 1, 10, 100);
	glMatrixMode(GL_MODELVIEW);
}

// =========Entrée Clavier============
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
// =============Main============
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
	mysnake = malloc(sizeof(char));
	char *recupid;
	recupid = malloc(sizeof(char));
	recv(socketclient, recupid, sizeof(char), 0);
	mysnake->id = recupid[0];
	printf("my snake is %c\n", mysnake->id);
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
	glutMainLoop();
	return EXIT_SUCCESS;
	return (0);
}