#include <unistd.h>

int my_strlen(const char str[])
{
    int i = 0;
    while ( str[i] != '\0')
    {
	i ++;
    }
    return(i);
}    
void lowerer(char str[])
{
    int len=my_strlen(str);
    int i=0;
    while (i<len)
    {
	if (str[i] > 64 && str[i] < 91)
	{
	    str[i]=str[i]+32;
	}
	i++;
    }
	return;
}

int  main(int argc, char **argv)
{
    char a[]= "MedHi le JaGUar !!!";
    lowerer(a);
    int len=my_strlen(a);
    write(STDOUT_FILENO,a,len);
    write(STDOUT_FILENO,"\n",2);
    
}
	
    