#include "data.h"
#include <unistd.h>
#include <stdio.h>
void  print(t_cell map[SIZE_X][SIZE_Y])
{
    write(STDOUT_FILENO,"print\n",6);
    t_cell caze;
    t_cell writ[1];
    char cpt = 0;
    char i = 0;
    char j = 0;
    while (i < SIZE_X)
    {
	while (j < SIZE_Y)
	{
	    caze = map[i][j];
	    if  (caze == 0)
	    {
		writ[0] = '.';
	    }
	    else if (caze == 1)
	    {
		writ[0] = 'X';
	    }
	    else
	    {
		writ[0] = 'E';
	    }
	    write(STDOUT_FILENO,writ,1);
	    cpt++;
	    if (cpt == SIZE_Y)
	    {
		write(STDOUT_FILENO,"\n",1);
		cpt = 0;
	    }
	    else
	    {
		write(STDOUT_FILENO," ",1);
	    }
	    j++;
	}
	j=0;
	i++;
    }
    return;
}
