#include "snake.h"

// all variables initialized to 1.0, meaning
// the triangle will initially be white
float red = 1.0f, blue = 1.0f, green = 1.0f;

float x = 0;
float y = 0;
float z = 100;
char generate = 'N';

// gestion du temps;
int reftime;
struct timespec now;
struct temps *tim;
struct temps *spawn;
struct temps *start;
struct tm *local;
struct tm *loca;
time_t star;
char begin;

// gestion de la food;
struct element *food;

// gestion du snake;
struct element *snake;
struct Snakecorps *corps;
struct element *snakehead;
int j;

// etat du deplacement
char *state = "start";
// initialisation;
void creationfood(void)
{
	food->x = (rand() % 162) - 81;
	food->y = (rand() % 162) - 81;
	printf("food créée en  x = %d ;  y = %d\n", food->x, food->y);
	return;
}
void initialize(void)
{
	tim = malloc(sizeof(s_temps));
	tim->s = 0;
	tim->ns = 0;
	start = malloc(sizeof(s_temps));
	start->s = -1;
	start->ns = -1;
	food = malloc(sizeof(s_elem));
	creationfood();
	corps = malloc(sizeof(s_Snakecorps));
	snakehead = malloc(sizeof(s_elem));
	snakehead->x = x;
	snakehead->y = y;
	snakehead->prev_x = 0;
	snakehead->prev_y = 0;
	corps->head = snakehead;

	return;
}
void startchronos(void)
{

	time(&star);
	loca = localtime(&star);
	start->h = loca->tm_hour;
	start->min = loca->tm_min;
	start->s = loca->tm_sec;
	begin = 'Y';
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
	if ((subs >= 5))
	{
		generate = 'Y';
		begin = 'N';
	}
	return (generate);
}
void resetsnake(void)
{
	s_elem *save;
	s_elem *tmp;
	tmp = corps->head;
	while (tmp->next != NULL)
	{
		save = tmp;
		tmp = tmp->next;
		free(save);
	}
	return;
}
void resetgame(void)
{
	free(tim);
	free(start);
	free(spawn);
	free(food);
	free(corps);
	free(snakehead);
	state = "start";
	return;
}
void controlestate(char *state)
{
	s_elem *tmp;
	tmp = corps->head;
	while (tmp->next != NULL)
	{
		tmp->prev_x = tmp->x;
		tmp->prev_y = tmp->y;
		tmp = tmp->next;
	}
	if (state == "right")
	{
		if (corps->head->x == 81)
		{
			corps->head->x = -81;
		}
		else
		{
			corps->head->x += 1;
		}
	}
	if (state == "down")
	{
		if (corps->head->y == -81)
		{
			corps->head->y = 81;
		}
		else
		{
			corps->head->y -= 1;
		}
	}
	if (state == "left")
	{
		if (corps->head->x == -81)
		{
			corps->head->x = 81;
		}
		else
		{
			corps->head->x -= 1;
		}
	}
	if (state == "up")
	{
		if (corps->head->y == 81)
		{
			corps->head->y = -81;
		}
		else
		{
			corps->head->y += 1;
		}
	}
	if (state == "reset")
	{
		//  clear du snake et de la nourrture.
		begin = 'N';
		generate = 'N';
		if (corps->head->next != NULL)
		{
			resetsnake();
		}
		resetgame();
		initialize();
	}
	if (state == "pause")
	{
		s_elem *tmp;
		tmp = corps->head;
		while (tmp->next != NULL)
		{
			tmp->prev_x = tmp->next->x;
			tmp->prev_y = tmp->next->y;
			tmp = tmp->next;
		}
		// arret de génération de nourriture.
		begin = 'Y';
		generate = 'N';
	}
	return;
}
void Add_corps(void)
{
	s_elem *Newcorps;
	Newcorps = malloc(sizeof(s_elem));
	Newcorps->next = corps->head;
	corps->head = Newcorps;
	Newcorps->prev_x = Newcorps->next->x;
	Newcorps->prev_y = Newcorps->next->y;
	Newcorps->x = Newcorps->prev_x;
	Newcorps->y = Newcorps->prev_y;
	return;
}
void checkfeed(void)
{
	if (food->x == corps->head->x && food->y == corps->head->y)
	{
		creationfood();
		while (j < 3)
		{
			Add_corps();
			j++;
		}
		j = 0;
	}
	return;
}
void checkcollision(void)
{
	if (corps->head->next != NULL)
	{
		s_elem *tmp;
		tmp = corps->head->next;
		while (state != "reset"  && tmp->next != NULL)
		{
			if (corps->head->x == tmp->x && corps->head->y == tmp->y)
			{
				state = "reset";
				printf("YOU LOOSE \n");
			}
			tmp = tmp->next;
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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0, 0, z,
				  0, 0, 0,
				  0.0f, 1.0f, 0.0f);
		controlestate(state);
		checkcollision();
		glBegin(GL_QUADS);
		glVertex3f(-1 + corps->head->x, 1 + corps->head->y, 0);
		glVertex3f(1 + corps->head->x, 1 + corps->head->y, 0);
		glVertex3f(1 + corps->head->x, -1 + corps->head->y, 0);
		glVertex3f(-1 + corps->head->x, -1 + corps->head->y, 0);
		glEnd();
		s_elem *tmp;
		tmp = corps->head;
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
	}
	if (begin == 'Y')
	{
		generate = checkchronos();
	}
	if (generate == 'Y')
	{
		checkfeed();
		glBegin(GL_TRIANGLES);
		glVertex3f(-1 + food->x, -1 + food->y, 0);
		glVertex3f(-1 + food->x, 1 + food->y, 0);
		glVertex3f(1 + food->x, 1 + food->y, 0);
		glEnd();
	}
	glutSwapBuffers();
}
void move(unsigned char key, int xi, int yi)
{
	if (key == 'q' && state != "right")
	{
			state = "left";
	}
	else if (key == 'd' && state != "left")
	{
			state = "right";
	}
	else if (key == 'z' && state != "down")
	{
			state = "up";
	}
	else if (key == 's' && state != "up")
	{
			state = "down";
	}
	else if (key == 'r')
	{
		state = "reset";
	}
	else if (key == 'p')
	{
		state = "pause";
	}
	if (start->s == -1 && start->ns == -1)
	{
		startchronos();
	}
	glutDisplayFunc(displayf);
}

void reshape(int a, int b)
{
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
	gluPerspective(80, 1, 10, 100);
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	initialize();
	int get;
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
	return EXIT_SUCCESS;
	return (0);
}
