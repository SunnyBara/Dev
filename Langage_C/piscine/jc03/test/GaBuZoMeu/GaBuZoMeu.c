#include <unistd.h>
#include "my_pow.h"
#include <stdio.h>
int initialisation(char tab[], int n)
{
    int i = 0;
    while (i < n)
    {
	tab[i] = 0;
	i++;
    }
    return(0);
}
int ligne(char syllabe[4][3], char tab[], int n)
{
    char writ[3];
    int cpt = 1;
    int k = 0;
    int i = 0;
    int j;
    while (i < n)
    {
	j=2;
	k = tab[n-(i+1)];
	writ[0] = syllabe[k][0];
	writ[1] = syllabe[k][1];
	writ[2] = syllabe[k][2];
	if (writ[2] == 'u')
	{
	    j = 3;
	}
	write(STDOUT_FILENO,writ,j);
	if (cpt == n)
	{
	    write(STDOUT_FILENO,"\n",1);
	    cpt=1;
	}
	else
	{
	    write(STDOUT_FILENO," " ,1);
	    cpt++;
	}
	i++;
    }
    return(0);
}
int avancement(char tab[],int n)
{
    int i = 0;
    tab[i] = tab[i] + 1;
    while (i < n)
    {
	if (tab[i] == 4)
	{
	    tab[i] = 0;
	    tab[i+1] = tab[i+1] + 1;
	}
	i++;
    }
    return(0);
}
int ga_bu_zo_meu(int n)
{   
    char syllabe[4][3];
    syllabe[0][0] = 'B';
    syllabe[0][1] = 'u';
    syllabe[0][2] = '0';
    syllabe[1][0] = 'G';
    syllabe[1][1] = 'a';
    syllabe[1][2] = '0';
    syllabe[2][0] = 'M';
    syllabe[2][1] = 'e';
    syllabe[2][2] = 'u';
    syllabe[3][0] = 'Z';
    syllabe[3][1] = 'o';
    syllabe[3][2] = '0';
    char tab[n];
    initialisation(tab,n);
    int taille = my_pow(4,n);
    int i = 0;
    while (i < taille)
    {
	ligne(syllabe,tab,n);
	avancement(tab,n);
	i++;
    }
    return(0);
}
