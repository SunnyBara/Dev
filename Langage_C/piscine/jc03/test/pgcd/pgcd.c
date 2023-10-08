int pgcd(int a, int b)
{
    int nbr1 = a;
    int nbr2 = b;
    while (nbr1 > 0 && nbr2 > 0)
    {
	while ( nbr1 > 0 && a%nbr1 != 0)
	{
	    nbr1 --;
	}
	while (nbr2 > 0 && b%nbr2 != 0)
	{
	    nbr2 --;
	}
	if (nbr2 > nbr1)
	{
	    nbr2--;
	}
	else if (nbr1 > nbr2)
	{
	    nbr1--;
	}
	else
	{
	    return(nbr1);
	}
    }
    return(1);
}
