#include <unistd.h>
int  max( const int vec[],int size)
{
  int i = 1;
  int l =0;
  int k = vec[0];
    while (i < size)
      {
	if ( k < vec[i])
	  {
	    l = k;
	    k = vec[i];	   
	  }
	i+=1;
      }
    return(l);
}
int main( int argc, char **argv)
{
  int vec[4];
  vec[0] = 41;
  vec[1] = 48;
  vec[2] = 55;
  vec[3] = 59;
  return( max(vec, 4));
}
