int min(const int tab[], int size)
{
    char i = 1;
    char min = tab[0];
    while (i < size)
    {
	if (tab[i] < min)
	{
	    min = tab[i];
        }
	i++;
    }
    return(min);
}
