#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{  
  char *a=malloc(2);
  a[0]=65;
  a[1]='\n';
  int  i=0; 
  while (i<26)
        {
	  write(STDOUT_FILENO, a, 2);
          i+=1;
	  a[0]+=1;  
       	}
  return(0);
}
