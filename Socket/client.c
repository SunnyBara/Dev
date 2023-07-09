#include "lib.h"
#include "pthread.h"

typedef struct player
{
    int pos_x;
    char *name;
    int pos_y;
} s_player;


int main(void)
{   s_player *player;
    player = malloc(sizeof(s_player));
    player->name = malloc(10*sizeof(char));
    player->pos_x = 45;
    player->pos_y = 72;
    player->name = "bob\0";
    int SocketClient = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrserv;
    addrserv.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrserv.sin_family = AF_INET;
    addrserv.sin_port = htons(4555);
    memset(&(addrserv.sin_zero), '\0', 8);

    // connecte le socket a l'addresse specifiee dans sockaddr.
    // usage client vers serveur
    // int connect(int sockfd, struct sockaddr *serv_addr, socklen_t addrlen);
    if (connect(SocketClient, (struct sockaddr *)&addrserv, sizeof(struct sockaddr)))
    {
        perror("connect");
        exit(1);
    }
    printf("player->name : %s\n", player->name);
    send(SocketClient,player,18,0);
    close(SocketClient);
    return 0;
}