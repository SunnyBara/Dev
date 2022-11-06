#include "jc05.h"
#include "stdio.h"
char *reverse(char *s)
{
  int stop = mystrlen(s)-1;
  char save;
  int i = 0;
  while (i<stop/2)
  {
    save = s[i];
    s[i] = s[stop-i];
    s[stop-i] = save;
    i++;
  }  
  return(s);
}