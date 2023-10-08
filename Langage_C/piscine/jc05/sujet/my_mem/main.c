#include "my_mems.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include  <unistd.h>
/*
void my_memsetest()
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore memset(): %s\n", str);
    memset(str +5, '.', 8*sizeof(char));
    printf("After memset():  %s\n", str);


    char mystr[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore mymemset(): %s\n", mystr);
    memset(mystr+5, '.', 8);
    printf("After mymemset():  %s\n", mystr);

}
void my_memcpytest()
{ 
   int tab[5];
   int i = 0;
   while (i < 5)
   {
    tab[i] = 1;
    printf("%i",tab[i]);
    i++;
   }
   printf("\n");
  //  const int *src = (const int*)tab;
    int mydest[5];
    my_memcpy(mydest, tab, 5*4);
    printf("After memcpy dest = ");
    i = 0;
    while (i < 5)
   {
    printf("%i-",mydest[i]);
    i++;
   }
   printf("\n");
   return;
}

void my_memovtest()
{
  
   int tab[5];
   int i = 0;
   while (i < 5)
   {
    tab[i] = i;
    printf("%i",tab[i]);
    i++;
   }
   printf("\n");
   const int *src = (const int*)tab;
   int mydest[5];
    printf("before  memmov dest = ");
    i = 0;
   while (i < 5)
   {
    printf("%i-",mydest[i]);
    i++;
   }
   printf("\n");
   my_memov(mydest, src, 12);
   printf("After memmov dest = ");
   i = 0;
   while (i < 5)
   {
    printf("%i-",mydest[i]);
    i++;
   }
   printf("\n");
   return;
}
*/
void my_memdumptest()
{
  char *buf = "chiche";
  memdump(buf, 60);
  return;
}

char conversion(char c)
{
   if (c < 10)
  {
    c = c + 48;
  }
  else 
  {
    c = c + 87;
  }
  return(c);
}
char* hexa(unsigned char a)
{
  char *tab;
  tab = malloc(2*sizeof(char));
  int hexin;
  int unitin;
  char unit ;
  char hexad;
  int aint = (int) a;
  unit   = a%16;
  hexad  = (a-unit)/16;
  unitin = (int) unit;
  hexin = (int) hexad;
  unit   = conversion(unit);
  hexad  = conversion(hexad);
  tab[1] = unit;
  tab[0] = hexad;
  return(tab);
}

int main(int argc, char **argv)
{
  int *ptr;
  int i=0;
  ptr = array_init(10);
//array_release(ptr);
//my_realloc(ptr,7,40);
//my_memsetest();
//my_memcpytest();
//my_memovtest();
//my_memdumptest();
while (i < 5)
{ 
  ptr[i] = 10 - i;
  i++;
}
while (i < 10)
{
  ptr[i] = 30  -2*i;
  i++;
}
array_sort(ptr,10);
array_fibo(ptr,4,6);
return(0);
}
