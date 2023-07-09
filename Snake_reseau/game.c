#include "snake.h"

//=============================VARIABLES==========================

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

//==========================
// serveur info
//=========================
typedef struct socketcerveur
{
    int socket;
} s_servsock;
typedef struct Serveurinfo
{
    char id;
    char action;
    int pos_x;
    int pos_y;
} s_servinf;

struct sendpos *sendpos;
typedef struct ClientList
{
    int socket;
    char id;
    struct element *snakehead;
    struct ClientList *next;
} s_clilist;

s_servsock *server;
s_clilist *liste;

//===========================
// gestion du snake;
//===========================
typedef struct element
{
    int x;
    int y;
    int prev_x;
    int prev_y;
    char *state;
    char action;
    struct element *next;
} s_elem;
struct element *food;
int j;

//=======================================Fonction=============================
//===========================
// gestion de la food;
//===========================

// position food
void sendall(s_servinf *infosend)
{
    s_clilist *tmp;
    tmp = liste;
    while (tmp != NULL)
    {
        send(tmp->socket, infosend, sizeof(s_servinf), 0);
        tmp = tmp->next;
    }
    return;
}

void creationfood(void)
{
    s_servinf *infosend;
    infosend = malloc(sizeof(s_servinf));
    food->x = (rand() % 162) - 81;
    food->y = (rand() % 162) - 81;
    infosend->id = 'f';
    infosend->pos_x = food->x;
    infosend->pos_y = food->y;
    sendall(infosend);
    free(infosend);
    return;
}

//==========================
// gestion du temps;
//==========================

void startchronos(void)
{
    time(&star);
    loca = localtime(&star);
    start->h = loca->tm_hour;
    start->min = loca->tm_min;
    start->s = loca->tm_sec;
    return;
}
void checkchronos(void)
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
        creationfood();
    }
    return;
}

//===========================
// initialisation;
//===========================
void initialize(void)
{
    printf("initialise\n");
    tim = malloc(sizeof(s_temps));
    tim->s = 0;
    tim->ns = 0;
    start = malloc(sizeof(s_temps));
    start->s = -1;
    start->ns = -1;
    food = malloc(sizeof(s_elem));
    return;
}

void resetsnake(char id)
{
    s_clilist *tmp = liste;
    while (id != tmp->id)
    {
        tmp = tmp->next;
    }
    // Préservation de la tête.
    tmp->snakehead = tmp->snakehead->next;
    s_elem *save;
    while (tmp->snakehead->next != NULL)
    {
        save = tmp->snakehead;
        tmp->snakehead = tmp->snakehead->next;
        free(save);
    }
    return;
}

void Add_corps(char id)
{
    s_elem *Newcorps;
    Newcorps = malloc(sizeof(s_elem));
    s_clilist *tmp = liste;
    while (id != tmp->id)
    {
        tmp = tmp->next;
    }
    Newcorps->next = tmp->snakehead;
    tmp->snakehead = Newcorps;
    Newcorps->prev_x = Newcorps->next->x;
    Newcorps->prev_y = Newcorps->next->y;
    Newcorps->x = Newcorps->prev_x;
    Newcorps->y = Newcorps->prev_y;
    return;
}
void checkfeed(void)
{
    printf("checkfeed\n");
    s_clilist *tmp;
    tmp = liste;
    while (tmp != NULL)
    {
        if (food->x == tmp->snakehead->x && food->y == tmp->snakehead->y)
        {
            creationfood();
            while (j < 3)
            {
                Add_corps(tmp->id);
                j++;
            }
            j = 0;
            tmp->snakehead->action = 'g';
        }
        tmp = tmp->next;
    }
    return;
}
void checkcollision(void)
{
    printf("checkcollision\n");
    s_clilist *tmpsnake;
    s_clilist *tmp;
    s_elem *tmpsnakebody;
    tmpsnake = liste;
    while (tmpsnake != NULL)
    {
        tmp = liste;
        while (tmp != NULL)
        {
            if (tmp->snakehead->next != NULL)
            {
                tmpsnakebody = tmpsnake->snakehead->next;
            }
            while (tmpsnake->snakehead->state[0] != 'R' && tmpsnakebody->next != NULL)
            {
                if (tmpsnake->snakehead->x == tmpsnakebody->x && tmpsnake->snakehead->y == tmpsnakebody->y)
                {
                    tmpsnake->snakehead->state = "Reset";
                }
                tmpsnakebody = tmpsnakebody->next;
            }
            tmp = tmp->next;
        }
        tmpsnake = tmpsnake->next;
    }
}

//==========================
// reception du client
//==========================

// accueil client

char addclient(s_clilist *newclient)
{
    printf("addclient\n");
    s_elem *snakehead;
    snakehead = malloc(sizeof(s_elem));
    snakehead->state = malloc(7 * sizeof(char));
    newclient->snakehead = snakehead;
    if (liste == NULL)
    {
        liste = malloc(sizeof(s_clilist));
        newclient->id = '1';
        liste = newclient;
    }
    else
    {
        char save;
        s_clilist *tmp;
        tmp = liste;
        while (tmp != NULL)
        {
            save = tmp->id;
            tmp = tmp->next;
        }
        tmp = newclient;
        newclient->id = save + 1;
    }
    return (newclient->id);
}

// thread client;

void *threadclient(void *arg)
{
    printf("dans le thread client\n");
    char *sendid = (char *)arg;
    char id = sendid[0];
    printf("thread client n°%c\n", id);
    s_clilist *tmp;
    tmp = liste;
    printf("recherche id\n");
    while (tmp->id != id)
    {
        tmp = tmp->next;
    }
    printf("l'id de ce client est n°%c\n", tmp->id);
    printf("socket du client n° %c est %i\n", tmp->id, tmp->socket);
    while (1)
    {
        usleep(500000);
        recv(tmp->socket, tmp->snakehead->state, 10, 0);
     //   printf("client n° %c state : %c\n", tmp->id, tmp->snakehead->state[0]);
    }
    return (NULL);
}

void *clilog(void *arg)
{
    // reception des clients
    while (1)
    {
        struct sockaddr_in addrclient;
        int size_min = sizeof(struct sockaddr_in);
        s_clilist *newclient;
        newclient = malloc(sizeof(s_clilist));
        listen(server->socket, 2);
        printf("attente d'un client \n");

        newclient->socket = accept(server->socket, (struct sockaddr *)&addrclient, &size_min);

        char id;
        char *sendid;
        sendid = malloc(sizeof(char));
        id = addclient(newclient);
        sendid[0] = id;
        send(newclient->socket, sendid, 2, 0);
        printf("ajout du client n° : %c sur la socket n° socket : %i\n", id, newclient->socket);

        void *voidcli = sendid;
        pthread_t client;
        printf("entré du thread client\n");
        pthread_create(&client, NULL, threadclient, voidcli);
    }
    return (NULL);
}

// etat du deplacement

void controlestate(void)
{
    printf("controlestate\n");
    s_clilist *tmp = liste;
    while (tmp != NULL)
    {
            tmp->snakehead->prev_x = tmp->snakehead->x;
            tmp->snakehead->prev_y = tmp->snakehead->y;
        if (tmp->snakehead->state[0] == 'r')
        {
            if (tmp->snakehead->x == 81)
            {
                tmp->snakehead->x = -81;
            }
            else
            {
                tmp->snakehead->x += 1;
            }
        }
        else if (tmp->snakehead->state[0] == 'd')
        {
            if (tmp->snakehead->y == -81)
            {
                tmp->snakehead->y = 81;
            }
            else
            {
                tmp->snakehead->y -= 1;
            }
        }
        else if (tmp->snakehead->state[0] == 'l')
        {
            if (tmp->snakehead->x == -81)
            {
                tmp->snakehead->x = 81;
            }
            else
            {
                tmp->snakehead->x -= 1;
            }
        }
        else if (tmp->snakehead->state[0] == 'u')
        {
            if (tmp->snakehead->y == 81)
            {
                tmp->snakehead->y = -81;
            }
            else
            {
                tmp->snakehead->y += 1;
            }
        }
        if (tmp->snakehead->state[0] == 'R')
        {
            //  reset du corps du snake et de sa position.
            if (tmp->snakehead->next != NULL)
            {
                resetsnake(tmp->id);
            }
            tmp->snakehead->x = 0;
            tmp->snakehead->y = 0;
            tmp->snakehead->prev_x = 0;
            tmp->snakehead->prev_y = 0;
            tmp->snakehead->action = 'r';
        }
        else
        {
            while(tmp->snakehead->next != NULL)
            {
                tmp->snakehead->next->x = tmp->snakehead->prev_x;
                tmp->snakehead->next->y = tmp->snakehead->prev_y;
                tmp->snakehead = tmp->snakehead->next;
            }
        }
        tmp = tmp->next;
    }
    return;
}

//===========================
// envoie au client
//==========================

// position snake

void sendposition(void)
{
     printf("sendposition\n");
    s_clilist *tmpclient;
    tmpclient = liste;
    while (tmpclient != NULL)
    {
        s_servinf *infosend;
        infosend = malloc(sizeof(s_servinf));
        infosend->id = tmpclient->id;
        infosend->pos_x = tmpclient->snakehead->x;
        infosend->pos_y = tmpclient->snakehead->y;
        infosend->action = tmpclient->snakehead->action;
        sendall(infosend);
        free(infosend);
        tmpclient = tmpclient->next;
    }
    return;
}

void game(void)
{
    initialize();
    while (1)
    {
        usleep(500000);
        // mutexlockstate;
        checkcollision();
        checkfeed();
        controlestate();
        sendposition();
        // mutexunlock;
    }
    return;
}

int main(int argc, char **argv)
{
    // set up du serveur.
    server = malloc(sizeof(s_servsock));
    server->socket = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrserver;
    addrserver.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrserver.sin_family = AF_INET;
    addrserver.sin_port = htons(5465);
    memset(&(addrserver.sin_zero), '\0', 8);
    bind(server->socket, (struct sockaddr *)&addrserver, sizeof(struct sockaddr));

    pthread_t clientlog;
    pthread_create(&clientlog, NULL, clilog, NULL);
    game();
    return (0);
}