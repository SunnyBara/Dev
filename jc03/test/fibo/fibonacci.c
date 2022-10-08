int fibonacci(int n)
{
    
    int i  = 1;
    int U[3];
     U[0] = 0;
     U[1] = 1;
     if (n == 1 || n == 0)
     {
	 return(U[n]);
     }
    
    while (i < n)
    {
	U[2] = U[1] + U[0];
	U[0] = U[1];
	U[1] = U[2];
	i++;
    }
    return(U[2]);
}
