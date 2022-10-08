#include <stdio.h>
int print_vec(const  int vec[], int size)
{
  int i=0;
  printf("[%i",vec[i]);  
    while (i+1 < size)
  {
  i+=1;
  printf(",%i",vec[i]);
  }
  printf("]");
}

int main(int argc, char **argv)
{
  int  a[5];
  a[0] = 4;
  a[1] = 5;
  a[2] = 8;
  a[3] = 7;
  a[4] = 9;
  int b = 5;
  return(print_vec(a,b));  
}
