#include <unistd.h>

int  main(int argc, char **argv)
{
  write (STDOUT_FILENO, "hello_world_!\n",15);
 return(0);
}