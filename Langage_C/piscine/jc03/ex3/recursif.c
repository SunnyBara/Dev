int fonction1(int n1,int n2)
{
  if (n2 == 0)
    {
      return(n1);
    }
  else
    {
      return(fonction1(n1, n2-1)+1);
    }
}
int main(int argc, char **argv)
{
  char n1=40;
  char n2=51;
  return(fonction1(n1,n2));
}
    
  
