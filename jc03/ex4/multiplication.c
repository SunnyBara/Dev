#include <stdio.h>
int SIZE_Y = 4;
int SIZE_X = 3;
void multiplication( const int m1[SIZE_Y][SIZE_X], const int m2[SIZE_X][SIZE_Y])
{
    int i = 0;
    int k = 0;
    int caze = 0;
    int j = 0;
    int m3[SIZE_Y][SIZE_Y];
    while (i < (SIZE_Y))
    {
	while (k < SIZE_Y)
	{      
	    while (j < (SIZE_X))
	    {
		caze = m1[i][j] * m2[j][k] + caze; 
		j++;
	    }
	    m3[i][k] = caze;
	    printf("%i ", m3[i][k]);
	    j=0;
	    k++;
	    caze = 0;
	}
	i ++;
	k = 0;
	printf("\n");
    }

    return;
}

int main(int argc , char **argv)
{
    int t[SIZE_Y][SIZE_X];
    int m[SIZE_X][SIZE_Y];
    t[0][0] = 1;
    t[0][1] = 1;
    t[0][2] = 1;
    t[1][0] = 1;
    t[1][1] = 1;
    t[1][2] = 1;
    t[2][0] = 1;
    t[2][1] = 1;
    t[2][2] = 1;
    t[3][0] = 1;
    t[3][1] = 1;
    t[3][2] = 1;
    m[0][0] = 2;
    m[0][1] = 2;
    m[0][2] = 2;
    m[0][3] = 2;
    m[1][0] = 2;
    m[1][1] = 2;
    m[1][2] = 2;
    m[1][3] = 2;
    m[2][0] = 2;
    m[2][1] = 2;
    m[2][2] = 2;
    m[2][3] = 2;
    multiplication(t,m);
    return(0);
}
