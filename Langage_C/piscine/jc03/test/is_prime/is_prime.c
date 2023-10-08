#include "my_sqrt.h"
int is_prime(int n)
{
    int i = 3;
    double racine = my_sqrt(n);
    if (  n % 2 == 0 && n != 2)
    {
	return(0);
    }
    while ( n % i != 0 &&  i < racine)
    {
	i = i + 2;
    }
    if (n % i != 0 || n == 2 )
    {
	return(1);
    }
    else
    {
	return(0);
    }
}
