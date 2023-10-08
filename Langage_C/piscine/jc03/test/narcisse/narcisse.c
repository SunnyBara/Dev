#include "my_pow.h"
#include <stdio.h>
int narcisse(unsigned int n)
{
    int saven = n;
    int taille = 1;
    int testaille = n;
    int puissance = 1;
    int addition = 0;
    while (testaille > 9)  
    {
	testaille = testaille / 10;
	taille ++;
	puissance = puissance *10;
    }
    int y = taille;
    while (taille > 0)
    {
	testaille = n / puissance;
	addition  = addition + my_pow(testaille,y);
	taille --;
	n = n - testaille*puissance;
	puissance = puissance / 10;
    }
    if (addition == saven)
    {
	return(1);
    }
    else
    {
	return(0);
    }
}
