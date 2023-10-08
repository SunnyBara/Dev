#include <stdio.h>
double my_atof(const char str[])
{
    double b;
    double ascii;
    char i = 0;
    double puissance = 0.1;
    double signe = 1;
    double result = 0;
    double test = 13.39;
    if (str[0] == '-')
    {
	i++;
	signe = -1;
    }
    else if (str[0] == '+')
    {
	i++;
    } 
    while (str[i] != '\0')
    {
      	if (str[i] == ',')
	{
	    i++;
	    break;
	}
	result = result*10 + (str[i]-48);
	i++;
    }
    while (str[i] != '\0')
    {
	ascii = str[i] -48;
	b = ascii*puissance;
	result = result +  b;
	puissance = puissance/10;
	i++;
    }
    result = signe*result;
    return(result);  
}

