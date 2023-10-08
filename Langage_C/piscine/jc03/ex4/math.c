#include <stdio.h>
int SIZE_Y = 4;
int SIZE_X = 3;
void print_math( const  int mat[SIZE_Y][SIZE_X])
{
    int i = 0;
    int j = 0;
    while (i < (SIZE_Y))
    {
	      
	while (j < (SIZE_X))
	{
	    printf("%i ", mat[i][j]);
	    j++;
	}
	printf("\n");
	j=0;
	i++;
    }
    return;
}

int main(int argc , char **argv)
{
    int t[SIZE_Y][SIZE_X];
    t[0][0] = 1;
    t[0][1] = 8;
    t[0][2] = 5;
    t[1][0] = 7;
    t[1][1] = 2;
    t[1][2] = 4;
    t[2][0] = 3;
    t[2][1] = 2;
    t[2][2] = 8;
    t[3][0] = 9;
    t[3][1] = 9;
    t[3][2] = 9;
    print_math(t);
    return(0);
}
