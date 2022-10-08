#include <unistd.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
  char  n = argv[2][0];
  char  i = 0;
  char  j = 0;
  while (argv[1][i] != '\0')
    {
      i+=1;
    }
  while (j<n-48)
  {
    write (STDOUT_FILENO, argv[1], i);
    write (STDOUT_FILENO, "\n", 2);
    j+=1;    
   }
  return(0);
}
