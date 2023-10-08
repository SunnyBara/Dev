int fibonacci(int n)
{
  if (n == 0)
  {
    return (0);
  }
  else if (n == 1)
  {
    return (1);
  }
  else
  {
    return (fibonacci(n - 2) + fibonacci(n - 1));
  }
}
int main(int argc, int **argv)
{
  char n = 10;
  return (fibonacci(n));
}

int fiboité(int n)
{
  int i = 0;
  int a = 0;
  int b = 1;
  int c = 999;
  while (i < 2)
  {
    c = a + b;
    a = b;
    b = c;
    i++;
  }
  return (c);
}