int my_pow(int x, int y)
{
    if(y==0)
    {
	return(1);
    }
    else if (y==1)
    {
	return(x);
    }
    if (y % 2 == 1)
    {
	y --;
	x = my_pow(x,y)*x;
    }
    else
    {
	  x = my_pow(x,y/2)*my_pow(x,y/2);
    }
    return(x);
}
