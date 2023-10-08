#include "my_atoi.h"
#include <stdio.h>
int  main(int argc, char **argv)
{
  char *t = argv[1];
  int len =  my_strlen(t);
  printf("%d\n", my_atoi(t));
  return(0);
}
