#include <stdio.h>
#include "data.h"
#include <unistd.h>
#include "game.h"
int load(t_cell map[SIZE_X][SIZE_Y])
{
    int j;
    int i;
    int l;
    char vali[1];
    int colonne;
    char ligne;
    t_cell writ[1];
    int cpt=0;
    i = getchar();
    i = i - 48;
    write(STDOUT_FILENO,"LOADING\n\n",9);
    while (l < 2)
    {
	getchar();
	l++;
    }
    l =0;
    j = getchar();
    j = j - 48;
    while (l < 2)
    {
	getchar();
	l++;
    }
    if (i != SIZE_X || j != SIZE_Y)
    {
	return(1);
    }
    colonne  = 0;
    ligne = 0;
    j = 0;
    i = 0;
    l = 0;
    while (ligne < SIZE_X)
    {
	while (j < SIZE_Y*2+1)
	{
	    l = getchar();
	    if ( l == 88)
	    {
	        map[ligne][colonne] = 1;
		colonne++;
		cpt ++;
	    }
	    else if ( l == 46)
	    {
		map[ligne][colonne] = 0;
		colonne++;
		cpt++;
	    }
	    j++;
	}
	ligne++;
	j = 0;
	colonne=0;
    }
    return(0);
}
