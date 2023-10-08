#include <unistd.h>
int branche (int n, int espace )
{
    int i = 1;
    int j = 0;
    int k = 1;
    while (i < n)
    {
	    while (j < espace)
	    {
		write(STDOUT_FILENO," ",1);
		j++; 
	    }
	    while (j < n+k)
	    {
		write(STDOUT_FILENO,"*",1);
		j++;
	    }
	
	espace --;
	i++;
	j=0;
	k++;
	write(STDOUT_FILENO,"\n",1);	    
    }
    
}
int base (int espace,int part)
{
    int i=0;
    int j=0;
    while (i < part)
    {
	while (j < espace)
	{
	    write(STDOUT_FILENO," ",1);
	    j++;
	}
	write(STDOUT_FILENO,"*",1);
	write(STDOUT_FILENO,"\n",1);
	i++;
	j=0;
    }
}
int sapin(int n)
{
    if (n < 3)
    {
	return(1);
    }
    else
    {
	base(n-1,1);
	branche(n,n-2);
	base(n-1,2);
    }
    return(0);
}
    
