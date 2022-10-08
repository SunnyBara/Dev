#include <unistd.h>

void ecriture( char table[], char j, char nombre[])
{
    char writ[1];
    char boucle = nombre[j];
    char position=0;
    char k = 0;
    while(k < j)
    {
	position = position + nombre[k];
	k++;
    }
    while  (boucle > 0)
    {
	writ[0] = table[position];
	write(STDOUT_FILENO,writ,1);
	boucle--;
	position++;
    }
    return;
}
void print_leet(const char str[])
{
    char chainmaj[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char chainmin[] = "abcdefghijklmnopqrstuvwxyz";
    char table[]  = "48[[)3!=6/-/|_/|<1|\\/||\\|()|><||257|_|\\/\\x/}{'/2";
    char nombre[26] = {1,1,1,2,1,2,1,3,1,2,2,1,4,3,1,2,2,2,1,1,3,2,3,2,2,1};
    char writ[1];
    char i = 0;
    char j = 0;
    while (str[i]   != '\0')
    {
	if (str[i] > 64 &&  str[i] < 91)
	{
	    while(str[i] != chainmaj[j])
	    {
		j++;
	    }
	    ecriture(table, j, nombre);
       	}
	else if (str[i] > 96 && str[i] < 123)
	{
	    while(str[i] != chainmin[j])
	    {
		j++;
	    }
	    ecriture(table, j, nombre);
	}	
	else
	{
	    writ[0] = str[i];
	    write(STDOUT_FILENO,writ,1);
	}
	i++;
	j = 0;
    }	
	
    return;
}
