int my_strlen(const char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
	i ++;
    }
    return(i);
}
int my_atoi(const char str[])
{
    int result = 0;
    int len =  my_strlen(str);
    int i = len-1;
    int puissance = 1;
    while  (i > 0)
    {
	result =  result + ((str[i] - 48) * puissance);
	puissance = puissance * 10;
	i--;
    }
    if (str[0] ==  '-')
    {
	result = -1 * result;
    }
    else if (str[0] != '+') 
    {
	result = result + ((str[0] - 48) * puissance);
    }
    return(result);  
}

