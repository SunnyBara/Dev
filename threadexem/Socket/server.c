#include "lib.h"
#include "pthread.h"
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
    char my_snake;
} s_servinf;

typedef struct etat
{
    char keystate;
    char *state;
    char savestate;

} s_etat;

typedef struct food
{
    int x;
    int y;
} s_food;
s_food *food;
int socketclient;
s_servinf *sendinfo;
s_etat *stat;

void controlestate(void)
{
    usleep(50000);
    if (stat->state[0] == 'r')
    {

        if (sendinfo->pos_x == 81)
        {
            sendinfo->pos_x = -81;
        }
        else
        {
            sendinfo->pos_x += 1;
        }
    }
    else if (stat->state[0] == 'd')
    {

        if (sendinfo->pos_y == -81)
        {
            sendinfo->pos_y = 81;
        }
        else
        {
            sendinfo->pos_y -= 1;
        }
    }
    else if (stat->state[0] == 'l')
    {

        if (sendinfo->pos_x == -81)
        {
            sendinfo->pos_x = 81;
        }
        else
        {
            sendinfo->pos_x -= 1;
        }
    }
    else if (stat->state[0] == 'u')
    {
        if (sendinfo->pos_y == 81)
        {
            sendinfo->pos_y = -81;
        }
        else
        {
            sendinfo->pos_y += 1;
        }
    }
    sendinfo->id = '1';
    sendinfo->pos_x = snake->x;
    sendinfo->pos_y = snake->y;
    send(socketclient, sendinfo, sizeof(s_servinf), 0);

    return;
}

void *confrecv(void *arg)
{

    while (1)
    {
        recv(socketclient, stat->state, 10, 0);
    }
}

void creationfood(void)
{
    food = malloc(sizeof(s_food));
    food->x = (rand() % 162) - 81;
    food->y = (rand() % 162) - 81;
    sendinfo->pos_x = food->x;
    sendinfo->pos_y = food->y;
    sendinfo->id = 'f';
    send(socketclient, sendinfo, sizeof(s_servinf), 0);
    return;
}

void game(void)
{
    creationfood();
    while (1)
    {
        controlestate();
    }
}

int main(int argc, char **argv)
{
    int socketsrveur = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrserver;
    addrserver.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrserver.sin_family = AF_INET;
    addrserver.sin_port = htons(5465);
    memset(&(addrserver.sin_zero), '\0', 8);
    bind(socketsrveur, (struct sockaddr *)&addrserver, sizeof(struct sockaddr));

    struct sockaddr_in addrclient;
    int size_min = sizeof(struct sockaddr_in);
    listen(socketsrveur, 2);
    printf("attente d'un client \n");

    socketclient = accept(socketsrveur, (struct sockaddr *)&addrclient, &size_min);
    sendinfo = malloc(sizeof(s_servinf));
    sendinfo->pos_x = 0;
    sendinfo->pos_y = 0;
    stat = malloc(sizeof(s_etat));
    stat->state = malloc(10 * sizeof(char));
    pthread_t fctrecv;
    pthread_create(&fctrecv, NULL, confrecv, NULL);
    game();
    pthread_join(fctrecv, NULL);
    close(socketclient);
    return (0);
}