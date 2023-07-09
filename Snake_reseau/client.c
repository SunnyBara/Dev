#include "snake.h"

//================================
// Paramètres d'affichages
//================================

// the triangle will initially be white
float red = 1.0f, blue = 1.0f, green = 1.0f;

float x = 0;
float y = 0;
float z = 100;

typedef struct etat
{
	char keystate;
	char *state;

} s_etat;

typedef struct Serveurinfo
{
	char id;
	char action;
	int pos_x;
	int pos_y;
} s_servinf;

typedef struct servesocket
{
	int socket;
} s_servesocket;
typedef struct Snake
{
	int nb;
	int pos_x;
	int pos_y;
} s_snake;
typedef struct element
{
	int x;
	int y;
	int prev_x;
	int prev_y;
	struct element *next;
} s_elem;

typedef struct snakelist
{
	int id;
	s_elem *snake_head;
	struct snakelist *next;
} s_snakelist;

typedef struct food
{
	int x;
	int y;
} s_food;

//=====================
// Variables
//======================
s_servesocket *serv;
s_etat *etat;
s_servinf *info;
s_snakelist *snakelist;
char mysnake;
s_food *food;

//==========================
// gestion du temps;
//==========================

int reftime;
struct timespec now;
struct temps *tim;
struct temps *spawn;
struct temps *start;
struct tm *local;
struct tm *loca;
time_t star;
char begin;

//================================
// déplacement à envoyer
//================================

void initialize(void)
{
	tim = malloc(sizeof(s_temps));
	tim->s = 0;
	tim->ns = 0;
	start = malloc(sizeof(s_temps));
	start->s = -1;
	start->ns = -1;
	etat = malloc(sizeof(s_etat));
	etat->state = malloc(7 * sizeof(char));
	info = malloc(sizeof(s_servinf));
	return;
}

//================================
// Remplissage de struct
//================================

// creation d'un nouveau snake;

s_snakelist *createsnake(char id)
{
	s_elem *newsnake_head;
	newsnake_head = malloc(sizeof(s_elem));
	newsnake_head->next = NULL;
	newsnake_head->x = 0;
	newsnake_head->y = 0;
	newsnake_head->prev_x = 0;
	newsnake_head->prev_y = 0;

	s_snakelist *newsnake;
	newsnake = malloc(sizeof(s_snakelist));
	newsnake->id = id;
	newsnake->snake_head = newsnake_head;
	newsnake->next = NULL;

	if (snakelist == NULL)
	{
		snakelist = newsnake;
		return (snakelist);
	}
	else
	{
		s_snakelist *tmp;
		tmp = snakelist;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newsnake;
		return (tmp->next);
	}
}

s_snakelist *findsnake(char id)
{
	s_snakelist *tmp;
	tmp = snakelist;
	while (snakelist != NULL && snakelist->id != info->id)
	{
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		return (createsnake(info->id));
	}
	return (tmp);
}

void resetsnake(s_snakelist *snake)
{
	s_snakelist *tmp;
	// Préservation de la tête.
	tmp->snake_head = tmp->snake_head->next;
	s_elem *save;
	while (tmp->snake_head->next != NULL)
	{
		save = tmp->snake_head;
		tmp->snake_head = tmp->snake_head->next;
		free(save);
	}
	return;
}

void Add_corps(s_snakelist *snake)
{
	s_elem *Newcorps;
	Newcorps = malloc(sizeof(s_elem));
	Newcorps->next = snake->snake_head;
	snake->snake_head = Newcorps;
	Newcorps->prev_x = Newcorps->next->x;
	Newcorps->prev_y = Newcorps->next->y;
	Newcorps->x = Newcorps->prev_x;
	Newcorps->y = Newcorps->prev_y;
}

void growsnake(s_snakelist *snake)
{
	int j = 0;
	while (j < 3)
	{
		Add_corps(snake);
		j++;
	}
	return;
}

// remplissage de structure

void *fillstruct(void *arg)
{
	recv(serv->socket, info, sizeof(s_servinf), 0);

	printf("info->id %i\n",info->id);
	if (info->id == 'f')
	{
		if (food == NULL)
		{
			food = malloc(sizeof(s_food));
		}
		food->x = info->pos_x;
		food->y = info->pos_y;
		return (NULL);
	}
	else if (info->id > 48 && info->id < 58)
	{
		s_snakelist *tmp;
		if (snakelist == NULL)
		{
			tmp = createsnake(info->id);
		}
		else
		{
			tmp = findsnake(info->id);
		}

		if (info->action = 'm')
		{
			tmp->snake_head->prev_x = tmp->snake_head->x;
			tmp->snake_head->prev_y = tmp->snake_head->y;
			tmp->snake_head->x = info->pos_x;
			tmp->snake_head->y = info->pos_y;
		}
		else if (info->action = 'g')
		{
			growsnake(tmp);
		}
		else if (info->action = 'r')
		{
			resetsnake(tmp);
		}
		return (NULL);
	}
}

//==========================
// AFFICHAGE
//==========================

void displayf(void)
{
	// affichage snake
	timespec_get(&now, TIME_UTC);
	if (now.tv_sec >= tim->s + 1 || now.tv_nsec >= tim->ns + 50000000)
	{
		tim->s = now.tv_sec;
		tim->ns = now.tv_nsec;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0, 0, z,
				  0, 0, 0,
				  0.0f, 1.0f, 0.0f);
		if (snakelist != NULL)
		{
			s_snakelist *tmpsnake;
			snakelist = tmpsnake;
			while (tmpsnake != NULL)
			{
				// Affichage de la tête
				printf("tmpsnake->x %i\n", tmpsnake->snake_head->x);
				glBegin(GL_QUADS);
				glVertex3f(-1 + tmpsnake->snake_head->x, 1 + tmpsnake->snake_head->y, 0);
				glVertex3f(1 + tmpsnake->snake_head->x, 1 + tmpsnake->snake_head->y, 0);
				glVertex3f(1 + tmpsnake->snake_head->x, -1 + tmpsnake->snake_head->y, 0);
				glVertex3f(-1 + tmpsnake->snake_head->x, -1 + tmpsnake->snake_head->y, 0);
				glEnd();
				s_elem *tmp;
				tmp = tmpsnake->snake_head;
				while (tmp->next != NULL)
				{
					// Affichage du corps
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
				tmpsnake = tmpsnake->next;
			}
		}
	}
	// affichage food
	if (food != NULL)
	{

		printf("affichage food\n");
		glBegin(GL_TRIANGLES);
		glVertex3f(-1 + food->x, -1 + food->y, 0);
		glVertex3f(-1 + food->x, 1 + food->y, 0);
		glVertex3f(1 + food->x, 1 + food->y, 0);
		glEnd();
	}
	glutSwapBuffers();
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
	send(serv->socket, etat->state, 10, 0);
	glutDisplayFunc(displayf);
}

//=============================
// Logique de jeu
//============================
void game(void)
{

	int argc;
	char **argv;
	int win;
	// INITIALIZATION
	glutInit(&argc, argv);
	// Size en pixels width * height
	glutInitWindowSize(400, 400);
	// Position x  y on the Window
	glutInitWindowPosition(750, 250);
	// Initial display mode
	glutInitDisplayMode(GLUT_RGBA);
	// Window Management
	win = glutCreateWindow("my window ");
	glutDisplayFunc(displayf);
	glutReshapeFunc(reshape);
	glutIdleFunc(displayf);
	glutKeyboardFunc(move);
	printf("Loop\n");
	//	glutReshapeWindow(800,800);
	glutMainLoop();
	return;
}
// ================================
// connexion au serveur
//================================

// envoie d'entré clavier
int main(int argc, char **argv)
{
	// connection au  serveur.
	serv = malloc(sizeof(s_servesocket));
	serv->socket = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addrserv;
	addrserv.sin_addr.s_addr = inet_addr("127.0.0.1");
	addrserv.sin_family = AF_INET;
	addrserv.sin_port = htons(5465);
	memset(&(addrserv.sin_zero), '\0', 8);
	if (connect(serv->socket, (struct sockaddr *)&addrserv, sizeof(struct sockaddr)))
	{
		perror("connect");
		exit(1);
	}

	// Demmande de pseudo
	char *msgrcv;
	msgrcv = malloc(150 * sizeof(char));
	recv(serv->socket, msgrcv, 150, 0);

	mysnake = msgrcv[0];
	printf("Vous êtes le client n° %c\n", mysnake);

	// game
	initialize();
	pthread_t fill;
	printf("creation thread fill\n");
	pthread_create(&fill, NULL, fillstruct, NULL);
	game();
	return (0);
}