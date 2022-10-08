#include <stdio.h>
int ppcm_recurse(int  multiple, int diviseur,int max, int i)
{
    if (multiple < diviseur*max)
    {
	if (multiple % diviseur == 0)
	{
	    return(multiple);
	}
	return(ppcm_recurse(max*i,diviseur,max,++i));
    }
    else
    {
	return(diviseur*max);
    }   
}
int ppcm(int a, int b)
{
    int diviseur;
    int max;
    if (a < b)
    {
	max = b;
	diviseur = a;
    }
    else
    {
	max = a;
	diviseur = b;
    }
    return(ppcm_recurse(max, diviseur, max, 1));
}
