#include "data.h"
#include "print.h"
#include <unistd.h>
void initialisation(t_cell mapc[SIZE_X][SIZE_Y])
{
    int i = 0;
    int j = 0;
    while (i < SIZE_X)
    {
	while (j < SIZE_Y)
	{
	    mapc[i][j] = 0;
	    j++;
	}
	i++;
	j=0;
    }
    return;
}
void check(t_cell map[SIZE_X][SIZE_Y])
{
    char writ[1];
    write(STDOUT_FILENO,"\nCheck\n",7);
    int i = 0;
    int j = 0;
    while (i < SIZE_X)
    {
	while (j < SIZE_Y)
	{
	    writ[0] = map[i][j]+48;
	    j++;
	    write(STDOUT_FILENO,writ,1);
	}
	write(STDOUT_FILENO,"\n",1);
	i++;
	j=0;
    }
    return;
}
void majmap(t_cell map[SIZE_X][SIZE_Y], t_cell mapc[SIZE_X][SIZE_Y])
{
    int i = 0;
    int j = 0;
    while (i < SIZE_X)
    {
	while (j < SIZE_Y)
	{
	    map[i][j] = mapc[i][j];
	    j++;
	}
	i++;
	j=0;
    }
    return;
}    
void coinHG (int i, int j, t_cell map[SIZE_X][SIZE_Y], t_cell mapc[SIZE_X][SIZE_Y])
{    
    if ( map[i][j+1] + map[i+1][j+1] + map[i+1][j] == 3)
    {	
	mapc[i][j] = 1;
    }
    else if (map[i][j+1] + map[i+1][j+1] + map[i+1][j] == 2)
    {
	mapc[i][j] = map[i][j];
    }
    else
    {
	mapc[i][j] = 0;
    }
    return;   
}
void coinHD (int i, int j, t_cell map[SIZE_X][SIZE_Y], t_cell mapc[SIZE_X][SIZE_Y])
{
    if (map[i][j-1] + map[i+1][j-1] + map[i+1][j] == 3)
    {
	mapc[i][j] = 1;
    }
    else if (map[i][j+1] + map[i-1][j+1] + map[i-1][j] == 2)
    {
	mapc[i][j] = map[i][j];
    }
    else
    {
	mapc[i][j] = 0;
    }
    return;
}
void coinBG (int i, int j, t_cell map[SIZE_X][SIZE_Y], t_cell mapc[SIZE_X][SIZE_Y])
{
    if (map[i][j+1] + map[i-1][j+1] + map[i-1][j] == 3)
    {
	mapc[i][j] = 1;
    }
    else if (map[i][j+1] + map[i-1][j+1] + map[i-1][j] == 2)
    {
	mapc[i][j] = map[j][i];
    }
    else
    {
	mapc[i][j] = 0;
    }
    return;
}
void coinBD (int i, int j, t_cell map[SIZE_X][SIZE_Y], t_cell mapc[SIZE_X][SIZE_Y])
{
    if (map[i][j-1] + map[i-1][j-1] + map[i-1][j] == 3)
    {
	mapc[i][j] = 1;
    }
    else if (map[i-1][j] + map[i-1][j-1] + map[i][j-1] == 2)
    {
	mapc[i][j] = map[i][j];
    }
    else
    {
	mapc[i][j] = 0;
    }
    return;
}
void ligneH(int i, int j, t_cell map[SIZE_X][SIZE_Y], t_cell mapc[SIZE_X][SIZE_Y])
{
    if (map[i][j-1] +  map[i][j+1] +  map[i+1][j-1] + map[i+1][j] + map[i+1][j+1] == 3) 
    {
	mapc[j][i] = 1;
    }
    else if (map[i][j-1] +  map[i][j+1] +  map[i+1][j-1] + map[i+1][j] + map[i+1][j+1] == 2) 
    {
	mapc[i][j] = map[i][j];
    }
    else
    {
	mapc[i][j] = 0;
    }
    return;
}
void ligneB(int i, int j, t_cell map[SIZE_X][SIZE_Y], t_cell mapc[SIZE_X][SIZE_Y])
{
    if (map[i-1][j-1] +  map[i-1][j] +  map[i-1][j+1] + map[i][j-1] + map[i][j+1] == 3) 
    {
	mapc[i][j] = 1;
    }
    else if (map[i-1][j-1] +  map[i-1][j] +  map[i-1][j+1] + map[i][j-1] + map[i][j+1] == 2)
    {
	mapc[i][j] = map[i][j];
    }
    else
    {
	mapc[i][j] = 0;
    }
    return;
}
void colonneG(int i, int j, t_cell map[SIZE_X][SIZE_Y], t_cell mapc[SIZE_X][SIZE_Y])
{
    if (map[i-1][j] +  map[i-1][j+1] +  map[i][j+1] + map[i+1][j] + map[i+1][j+1] == 3)
    {
	mapc[i][j] = 1;
    }
    else if (map[i-1][j] +  map[i-1][j+1] +  map[i][j+1] + map[i+1][j] + map[i+1][j+1] == 2)  
    {
	mapc[i][j] = map[i][j];
    }
    else
    {
	mapc[i][j] = 0;
    }
    return;
}
void colonneD(int i, int j, t_cell map[SIZE_X][SIZE_Y], t_cell mapc[SIZE_X][SIZE_Y])
{
    if (map[i-1][j-1] +  map[i-1][j] +  map[i][j-1] + map[i+1][j-1] + map[i+1][j] == 3) 
    {
	mapc[j][i] = 1;
    }
    else if (map[i-1][j-1] +  map[i-1][j] +  map[i][j-1] + map[i+1][j-1] + map[i+1][j] == 2)
    {
	mapc[i][j] = map[i][j];
    }
    else
    {
	mapc[i][j] = 0;
    }
    return;
}
void exterieur(int i, int j, t_cell map[SIZE_X][SIZE_Y],  t_cell mapc[SIZE_X][SIZE_Y])
{
    if  (i == 0)
    {
	if (j == 0)
	{
	    coinHG(i,j,map,mapc);
	}
	else if (j == SIZE_Y-1)
	{
	    coinHD(i,j,map,mapc);
	}
	else
	{
	    ligneH(i,j,map,mapc);
	}
	
    }
    else if  (i == SIZE_X-1)
    {
	if (j == 0)
	{
	    coinBG(i,j,map,mapc);
	}
	else if (j == SIZE_Y-1)
	{
	    coinBD(i,j,map,mapc);
	}
	else
	{
	    ligneB(i,j,map,mapc);
	}
    }
    else if (j == 0)
    {
	colonneG(i,j,map,mapc);
    }
    else
    {
	colonneD(i,j,map,mapc);
    }
    return;
}
void interieur(int i, int j, t_cell map[SIZE_X][SIZE_Y],  t_cell mapc[SIZE_X][SIZE_Y])
{
    if (map[i-1][j-1] +  map[i-1][j] +  map[i-1][j+1] + map[i][j-1] + map[i][j+1] + map[i+1][j-1] +  map[i+1][j] +  map[i+1][j+1] == 3) 
    {
	mapc[i][j] = 1;
    }
    else if (map[i-1][j-1] +  map[i-1][j] +  map[i-1][j+1] + map[i][j-1] + map[i][j+1] + map[i+1][j-1] +  map[i+1][j] +  map[i+1][j+1] == 2)
    {
	mapc[i][j] = map[i][j];
    }
    else
    {
	mapc[i][j] = 0;
    }
    return;  
    
}
void  game(t_cell map[SIZE_X][SIZE_Y])
{
    t_cell mapc[SIZE_X][SIZE_Y];
    int i = 0;
    int j = 0;
    initialisation(mapc);
    while (i < SIZE_X)
    {
	while (j < SIZE_Y)
	{
	    if (i == 0 || i == SIZE_X - 1)
	    {
		exterieur(i,j,map,mapc);
	    }
	    else 
	    {
		interieur(i,j,map,mapc);
	    }
	    j++;
	}
	i++;
	j=0;
    }
    majmap(map,mapc);
return;
}
