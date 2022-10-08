#include <stdio.h>
void tri_selection(int vec[], int size)
{
    int i=0;
    int p=0;
    while (i<size)
    {
	int k=vec[i];
	int j = i;
	while (j < size)
	{
	    if (k > vec[j])
	    {
		k = vec[j];
		p = j;
	    }
	    j+=1;
	}
	vec[p]=vec[i];
	vec[i]=k;
	i+=1;
    }
    return;
}

int main(int argc, char **argv)
{
    int vec[5];
    vec[0] = 7;
    vec[1] = 4;
    vec[2] = 0;
    vec[3] = 9;
    vec[4] = 2;
    tri_selection( vec, 5);
    int i=0;
    while (i < 5)
    {
	printf("%i",vec[i]);
	i+=1;
    }
    return(0);
}
