#include <unistd.h>
int sum(int i)
{
    char writ[1];
    int taille = 1;
    int puissance = 1;
    if (i  < 0)
    {
	i = i * -1;
	writ[0] = '-';
	write(STDOUT_FILENO,writ, 1);
    }
    int testaille = i;
    while (testaille > 9)  
    {
	testaille = testaille / 10;
	taille ++;
	puissance = puissance *10;
    }
    char addition = 0;
    while (taille > 0)
    {
	testaille = i / puissance;
	addition  = addition + testaille;
	taille --;
	i = i - testaille*puissance;
	puissance = puissance / 10;
    } 
    if  (addition < 10)
    {
	writ[0] =  addition+48;
	write(STDOUT_FILENO, writ, 1);
	write(STDOUT_FILENO, "\n", 1);
    }   
    else
    {
	return(sum(addition));
    }
}
