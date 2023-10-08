#include "../data/data.h"
#include "Allgame.h"
#include "../actions/allaction.h"

// gestion du temps;
int reftime;
struct timespec now;
struct temps *tim;
struct temps *spawn;
struct temps *start;
struct tm *local;
struct tm *loca;
time_t star;
float slow = 1;
char gamestate = 'S';

void startchronos(void)
{
    time(&star);
    loca = localtime(&star);
    start->h = loca->tm_hour;
    start->min = loca->tm_min;
    start->s = loca->tm_sec;
    return;
}
s_unit *sendinfo(s_unit *infotosend, s_unit *send)
{
    send->health = infotosend->health;
    send->next = NULL;
    send->owner = infotosend->owner;
    send->Y = infotosend->Y;
    send->X = infotosend->X;
    send->unitname = infotosend->unitname;
    send->stock_food = infotosend->stock_food;
    return (send);
}

void slowgame(float slowfactor)
{
    slow = slowfactor;
    while (1)
    {
        timespec_get(&now, TIME_UTC);
        if (now.tv_sec >= tim->s + 1 || now.tv_nsec >= tim->ns + slow * 50000000)
        {
            tim->s = now.tv_sec;
            tim->ns = now.tv_nsec;
            return;
        }
    }
}
void endgame(s_army *playerarmy)
{
    int player = playerarmy->owner;
    s_unit *tmp = playerarmy->firstunit;
    while (tmp != NULL && tmp->unitname[0] != 'q' && tmp->unitname[0] != 'r')
    {
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        printf("Player %d à perdu \n Fin de partie\n", player);
        gamestate = 'E';
    }
    return;
}

void erasearmy(s_army *army)
{
    s_unit *tmp = army->firstunit;
    s_unit *save;
    while (tmp != NULL)
    {
        save = tmp;
        tmp = tmp->next;
        free(save);
    }
    return;
}

void protocoleendgame(s_army *armylist)
{
    s_army *army1 = armylist;
    s_army *army2 = armylist->next;
    erasearmy(army1);
    erasearmy(army2);
    return;
}

void *tourdejeu(void *arg)
{
    tim = malloc(sizeof(s_temps));
    tim->s = 0;
    tim->ns = 0;
    start = malloc(sizeof(s_temps));
    start->s = -1;
    start->ns = -1;
    startchronos();
    s_pack *argument;
    argument = (s_pack *)arg;
    s_action *move;
    s_unit *tmpplayer1;
    s_unit *tmpplayer2;
    while (gamestate != 'E')
    {
        slowgame(slow);
        tmpplayer1 = argument->armylist->firstunit;
        tmpplayer2 = argument->armylist->next->firstunit;
        s_unit *send1;
        s_unit *send2;
        send1 = malloc(sizeof(s_unit));
        send2 = malloc(sizeof(s_unit));

        while (tmpplayer2 != NULL || tmpplayer1 != NULL)
        {
            if (tmpplayer1 != NULL)
            {
                send1 = sendinfo(tmpplayer1, send1);
                move = askaction1(tmpplayer1, sonar(tmpplayer1->X, tmpplayer1->Y, argument->maap));
                action(move->action, move->unit, move->cX, move->cY, argument->maap, argument->armylist, tmpplayer2);
                tmpplayer1 = tmpplayer1->next;
            }

            if (tmpplayer2 != NULL)
            {
                send2 = sendinfo(tmpplayer2, send2);
                move = askaction2(tmpplayer2, sonar(tmpplayer2->X, tmpplayer2->Y, argument->maap));
                action(move->action, move->unit, move->cX, move->cY, argument->maap, argument->armylist, tmpplayer1);
                tmpplayer2 = tmpplayer2->next;
            }
            displayf();
        }
        free(send1);
        free(send2);
    }
    protocoleendgame(argument->armylist);
}
