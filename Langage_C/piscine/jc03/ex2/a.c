#include <unistd.h>

int main(int argc, char **argv)
{
  char t[1];
  t[0]=0;
  read(STDIN_FILENO, t, 1);
  while (t[0] != 'q')
  {
     write(STDOUT_FILENO, t, 1);
     read(STDIN_FILENO, t, 1);
  }
    return(0);
}
