#include <stdio.h>
#include <unistd.h>
int dicho_search( const int vec[], int size, int elt)
{
    int min   = 0;
    int max   = size;
    int pivot = (min  + max)/2;
    int i     = 0;
    int test  = pivot;
    while (i < test && elt != vec[pivot])
    {
	if ( min >= max)
  	{
	    return(1);  
  	}
	if (vec[pivot] <  elt)
	{
	    min = pivot + 1;
	    pivot = (min + max)/2;
	}
        else
	{
	    max = pivot -1;
	    pivot = (min  + max)/2;
	}
	i+=1;
    }
    if ( elt == vec[pivot])
	{
	    return (pivot);		     
	}
    else
    {
	return(1);
    }
}


int main(int  argc, char **argv)
{
    int vec[11];
    vec[0] = 0;
    vec[1] = 8;
    vec[2] = 10;
    vec[3] = 12;
    vec[4] = 15;
    vec[5] = 19;
    vec[6] = 25;
    vec[7] = 35;
    vec[8] = 75;
    vec[9] = 120;
    vec[10] = 155;   
    return(dicho_search(vec,11,12));
}
