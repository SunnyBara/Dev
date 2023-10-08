#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "pthread.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
// Partie serveur -> recoit les infos coté client et effectue des tâches.
// addresse ip publique : 176.181.88.56 => curl ifconfig.me
// ip inet : 127.0.0.1/8
typedef struct Serveurinfo
{
    char id;
    char action;
    int pos_x;
    int pos_y;
    int n;
} s_servinf;
typedef struct socketcerveur
{
    int socket;
} s_servsock;

typedef struct etat
{
    char keystate;
    char *state;
    char savestate;
} s_etat;
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

typedef struct ClientList
{
    int socket;
    char id;
    struct element *snakehead;
    struct ClientList *next;
} s_clilist;

typedef struct food
{
    int x;
    int y;
} s_food;

s_clilist *list;
s_food *food;
int socketclient;
s_etat *stat;
s_elem *snake;
s_servsock *server;
//====== Envoie des infos Clent===========
void sendall(s_servinf *sendinfo)
{
    s_clilist *tmp;
    tmp = list;
    while (tmp != NULL)
    {
        send(tmp->socket, sendinfo, sizeof(s_servinf), 0);
        tmp = tmp->next;
    }
    return;
}
void sendinfosnake(void)
{
    s_servinf *sendinfo;
    s_clilist *tmp;
    sendinfo = malloc(sizeof(s_servinf));
    tmp = list;
    while (tmp != NULL)
    {
        s_elem *tmpbody;
        tmpbody = tmp->snakehead;
        sendinfo->id = tmp->id;
        while (tmpbody != NULL)
        {
            sendinfo->action = tmpbody->action;
            sendinfo->pos_x = tmpbody->x;
            sendinfo->pos_y = tmpbody->y;
            sendinfo->n = tmpbody->n;
            sendall(sendinfo);
            tmpbody = tmpbody->next;
        }
        tmp = tmp->next;
    }
    free(sendinfo);
    return;
}
//========== Etat des snakes===========
void controlestate(void)
{
    usleep(50000);
    s_clilist *tmpsnake;
    s_elem *tmp;
    tmpsnake = list;
    while (tmpsnake != NULL)
    {
        tmp = tmpsnake->snakehead;
        while (tmp != NULL)
        {
            tmp->prev_x = tmp->x;
            tmp->prev_y = tmp->y;
            tmp = tmp->next;
        }
        if (tmpsnake->snakehead->state[0] == 'r')
        {

            if (tmpsnake->snakehead->x >= 81)
            {
                tmpsnake->snakehead->x = -81;
            }
            else
            {
                tmpsnake->snakehead->x += 1;
            }
        }
        else if (tmpsnake->snakehead->state[0] == 'd')
        {

            if (tmpsnake->snakehead->y <= -81)
            {
                tmpsnake->snakehead->y = 81;
            }
            else
            {
                tmpsnake->snakehead->y -= 1;
            }
        }
        else if (tmpsnake->snakehead->state[0] == 'l')
        {

            if (tmpsnake->snakehead->x <= -81)
            {
                tmpsnake->snakehead->x = 81;
            }
            else
            {
                tmpsnake->snakehead->x -= 1;
            }
        }
        else if (tmpsnake->snakehead->state[0] == 'u')
        {
            if (tmpsnake->snakehead->y >= 81)
            {
                tmpsnake->snakehead->y = -81;
            }
            else
            {
                tmpsnake->snakehead->y += 1;
            }
        }
        tmp = tmpsnake->snakehead;
        while (tmp->next != NULL)
        {
            tmp->next->x = tmp->prev_x;
            tmp->next->y = tmp->prev_y;
            tmp = tmp->next;
        }
        tmpsnake->snakehead->action = 'H';
        tmpsnake = tmpsnake->next;
    }
    return;
}

// ============Thread Client & ajout client=========
char addclient(s_clilist *newclient)
{
    printf("addclient\n");
    s_elem *snakehead;
    snakehead = malloc(sizeof(s_elem));
    snakehead->state = malloc(7 * sizeof(char));
    newclient->snakehead = snakehead;
    newclient->snakehead->action = 'H';
    newclient->snakehead->n = 0;
    if (list == NULL)
    {
        list = malloc(sizeof(s_clilist));
        newclient->id = '1';
        list = newclient;
    }
    else
    {
        s_clilist *tmp;
        tmp = list;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newclient;
        newclient->id = tmp->id + 1;
    }
    return (newclient->id);
}
void *threadclient(void *arg)
{
    char *sendid = (char *)arg;
    char id = sendid[0];
    s_clilist *tmp;
    tmp = list;
    while (tmp->id != id)
    {
        tmp = tmp->next;
    }
    while (1)
    {
        recv(tmp->socket, tmp->snakehead->state, 10, 0);
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
        pthread_create(&client, NULL, threadclient, voidcli);
    }
    return (NULL);
}
// ==========Gestion de la food========
void sendfood(void)
{
    s_servinf *sendinfo;
    sendinfo = malloc(sizeof(s_servinf));
    sendinfo->pos_x = food->x;
    sendinfo->pos_y = food->y;
    sendinfo->id = 'f';
    sendinfo->action = 'F';
    sendinfo->n = -1;
    sendall(sendinfo);
    free(sendinfo);
}

void creationfood(void)
{
    food->x = (rand() % 162) - 81;
    food->y = (rand() % 162) - 81;
    sendfood();
    return;
}
//=======Gestion du snake========
void Add_corps(s_clilist *tmplist)
{
    s_elem *Newcorps;
    s_elem *tmp;
    Newcorps = malloc(sizeof(s_elem));
    Newcorps->next = tmplist->snakehead;
    tmplist->snakehead->action = 'C';
    tmplist->snakehead = Newcorps;
    Newcorps->prev_x = Newcorps->next->x;
    Newcorps->prev_y = Newcorps->next->y;
    Newcorps->x = Newcorps->prev_x;
    Newcorps->y = Newcorps->prev_y;
    Newcorps->action = 'H';
    Newcorps->n = 0;
    tmp = Newcorps;
    while (tmp->next != NULL)
    {
        tmp->next->n = tmp->n + 1;
        tmp = tmp->next;
    }

    Newcorps->next->n = Newcorps->n + 1;
    Newcorps->state = Newcorps->next->state;
    return;
}

void checkfeed(void)
{
    s_clilist *tmplist;
    tmplist = list;
    while (tmplist != NULL)
    {
        if (food->x == tmplist->snakehead->x && food->y == tmplist->snakehead->y)
        {
            creationfood();
            int j = 0;
            while (j < 3)
            {
                Add_corps(tmplist);
                j++;
            }
        }
        tmplist = tmplist->next;
    }
    return;
}

void resetsnake(s_clilist *tmplist)
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
    tmplist->snakehead->action = 'R';
    return;
}

void checkcollision(void)
{
    s_clilist *tmplist;
    tmplist = list;
    while (tmplist != NULL)
    {
        s_elem *tmp;
        s_clilist *othersnake;
        othersnake = list;
        while (othersnake != NULL)
        {
            tmp = othersnake->snakehead;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
                if (tmplist->snakehead->x == tmp->x && tmplist->snakehead->y == tmp->y)
                {
                    resetsnake(tmplist);
                    break;
                }
            }
            othersnake = othersnake->next;
        }
        tmplist = tmplist->next;
    }
    return;
}
//======== Boucle game ============
void game(void)
{
    food = malloc(sizeof(s_food));
    creationfood();
    while (1)
    {
        controlestate();
        checkcollision();
        checkfeed();
        sendinfosnake();
        sendfood();
    }
}
//==============Fonction main========
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
    if (list == NULL)
    {
        while (list == NULL)
        {
            sleep(1);
        }
    }
    game();
    pthread_join(clientlog, NULL);
    close(socketclient);
    return (0);
}
