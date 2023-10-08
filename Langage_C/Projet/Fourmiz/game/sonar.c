#include "../data/data.h"

s_maap *addlist(s_maap *list, s_maap *casedescript)
{
    s_maap *newcase;
    newcase = malloc(sizeof(s_maap));
    newcase->X = casedescript->X;
    newcase->Y = casedescript->Y;
    newcase->next = NULL;
    newcase->state = casedescript->state;
    newcase->phero = casedescript->phero;
    newcase->food = casedescript->food;
    s_maap *tmp;
    tmp = list;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newcase;

    return (list);
}

s_maap *search(s_maap *list, s_maap *maap, int cX, int cY)
{
    s_maap *tmp;
    tmp = find(cX, cY, maap);
    list = addlist(list, tmp);
    return (list);
}
s_maap *gameHG(s_maap *list, s_maap *maap, int cX, int cY)
{
    list = search(list, maap, cX + 1, cY);
    list = search(list, maap, cX + 1, cY + 1);
    list = search(list, maap, cX, cY + 1);
    return (list);
}
s_maap *gameHD(s_maap *list, s_maap *maap, int cX, int cY)
{
    list = search(list, maap, cX, cY - 1);
    list = search(list, maap, cX + 1, cY - 1);
    list = search(list, maap, cX + 1, cY);
    return (list);
}

s_maap *gameBG(s_maap *list, s_maap *maap, int cX, int cY)
{
    list = search(list, maap, cX - 1, cY);
    list = search(list, maap, cX - 1, cY + 1);
    list = search(list, maap, cX, cY + 1);
    return (list);
}

s_maap *gameBD(s_maap *list, s_maap *maap, int cX, int cY)
{
    list = search(list, maap, cX - 1, cY - 1);
    list = search(list, maap, cX - 1, cY);
    list = search(list, maap, cX, cY - 1);
    return (list);
}

s_maap *gameLH(s_maap *list, s_maap *maap, int cX, int cY)
{
    list = search(list, maap, cX, cY - 1);
    list = search(list, maap, cX, cY + 1);
    list = search(list, maap, cX + 1, cY - 1);
    list = search(list, maap, cX + 1, cY);
    list = search(list, maap, cX + 1, cY + 1);
    return (list);
}
s_maap *gameLB(s_maap *list, s_maap *maap, int cX, int cY)
{

    list = search(list, maap, cX - 1, cY - 1);
    list = search(list, maap, cX - 1, cY);
    list = search(list, maap, cX - 1, cY + 1);
    list = search(list, maap, cX, cY - 1);
    list = search(list, maap, cX, cY + 1);
    return (list);
}

s_maap *gameCG(s_maap *list, s_maap *maap, int cX, int cY)
{
    list = search(list, maap, cX - 1, cY);
    list = search(list, maap, cX - 1, cY + 1);
    list = search(list, maap, cX, cY + 1);
    list = search(list, maap, cX + 1, cY);
    list = search(list, maap, cX + 1, cY + 1);
    return (list);
}

s_maap *gameCD(s_maap *list, s_maap *maap, int cX, int cY)
{
    list = search(list, maap, cX - 1, cY - 1);
    list = search(list, maap, cX - 1, cY);
    list = search(list, maap, cX, cY - 1);
    list = search(list, maap, cX + 1, cY - 1);
    list = search(list, maap, cX + 1, cY);
    return (list);
}

s_maap *gameint(s_maap *list, s_maap *maap, int cX, int cY)
{
    list = search(list, maap, cX - 1, cY - 1);
    list = search(list, maap, cX - 1, cY);
    list = search(list, maap, cX - 1, cY + 1);
    list = search(list, maap, cX, cY - 1);
    list = search(list, maap, cX, cY + 1);
    list = search(list, maap, cX + 1, cY - 1);
    list = search(list, maap, cX + 1, cY);
    list = search(list, maap, cX + 1, cY + 1);
    return (list);
}

s_maap *gameext(s_maap *list, s_maap *maap, int cX, int cY, int X, int Y)
{
    if (cX == 0)
    {
        if (cY == 0)
        {
            list = gameHG(list, maap, cX, cY);
        }
        else if (cY == Y)
        {
            list = gameHD(list, maap, cX, cY);
        }
        else
        {
            list = gameLH(list, maap, cX, cY);
        }
    }
    else if (cX == X)
    {
        if (cY == 0)
        {
            list = gameBG(list, maap, cX, cY);
        }
        else if (cY == Y)
        {
            list = gameBD(list, maap, cX, cY);
        }
        else
        {
            list = gameLB(list, maap, cX, cY);
        }
    }
    else if (cY == 0)
    {
        list = gameCG(list, maap, cX, cY);
    }
    else if (cY == Y - 1)
    {
        list = gameCD(list, maap, cX, cY);
    }
    return (list);
}

s_maap *sonar(int cX, int cY, s_maap *maap)
{
    s_maap *eof;
    eof = maap;
    while (eof->next != NULL)
    {
        eof = eof->next;
    }
    s_maap *tmp = find(cX, cY, maap);
    s_maap *list;
    list = malloc(sizeof(s_maap));
    list->next = NULL;
    list->X = cX;
    list->Y = cY;
    list->state = tmp->state;
    list->phero = tmp->phero;
    list->food = tmp->food;
    if (cX == 0 || cX == eof->X || cY == 0 || cY == eof->Y)
    {
        list = gameext(list, maap, cX, cY, eof->X, eof->Y);
    }
    else
    {
        list = gameint(list, maap, cX, cY);
    }
    return (list);
}