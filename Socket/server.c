#include "lib.h"
#include "pthread.h"

// Partie serveur -> recoit les infos coté client et effectue des tâches.
// addresse ip publique : 176.181.88.56 => curl ifconfig.me
// ip inet : 127.0.0.1/8

typedef struct player
{
    int pos_x;
    char *name;
    int pos_y;
} s_player;



int fill(char *stringtofill, int size, char *filler, int starter)
{
    int i = 0;
    while (i < size)
    {
        stringtofill[i] = filler[starter + i];
        i++;
    }
    return (starter + i);
}

int main(int argc, char **argv)
{
    int socketclient;
    int size_min = sizeof(struct sockaddr_in);
    struct sockaddr_in addrclient;
    struct sockaddr_in addrserver;
    addrserver.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrserver.sin_port = htons(4555);
    addrserver.sin_family = AF_INET;
    s_player *player;
    player = malloc(sizeof(s_player));
    player->name = malloc(10 * sizeof(char));
    int socketserver = socket(PF_INET, SOCK_STREAM, 0);
    memset(&(addrserver.sin_zero), '\0', 8);
    bind(socketserver, (struct sockaddr *)&addrserver, sizeof(struct sockaddr));

    listen(socketserver, 5);
    printf("attente d'un client \n");
    socketclient = accept(socketserver, (struct sockaddr *)&addrclient, &size_min);
    printf("Client accepté\n");

    recv(socketclient, player, 18, 0);
    printf("player->name %s\n", player->name);

    printf("player :\n pos_X : %d \n pos_Y : %d\n Name : %s\n ", player->pos_x, player->pos_y, player->name);
    return (0);
}