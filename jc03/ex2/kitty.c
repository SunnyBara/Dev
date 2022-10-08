#include <unistd.h>

int main(int argc, char **argv)
{
  char t[100];
  read(STDIN_FILENO, t, 100);
  write(STDOUT_FILENO, t, 100);
  return (0);
}
