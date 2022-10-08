double my_sqrt(double x)
{
    double U[2];
    U[0] = 1;
    U[1] = (0.5)*(U[0] + (x/U[0]));
    double precision = 0.0000001;
    double test = U[1] - U[0];
    if (x < 0)
    {
	return(-1);
    }
    while ( test > precision )
    {
	U[0] =(0.5)*(U[1] + (x/U[1]));
	test = (U[1] - U[0]);
	U[1] = U[0];
    }
    return(U[0]);
}
