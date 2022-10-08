#include <unistd.h>
#include <stdio.h>
int  max( const int vec[],int size)
{
  int i = 1;
  int k = vec[0];
    while (i < size)
      {
	if ( k < vec[i])
	  {
	    k = vec[i];	   
	  }
	i+=1;
      }
    return(k);
}
int main( int argc, char **argv)
{
  int vec[4];
  vec[0] = -41;
  vec[1] = -48;
  vec[2] = -55;
  vec[3] = -59;
  printf( "%i",max(vec,4) );
  return( max(vec, 4));
}
