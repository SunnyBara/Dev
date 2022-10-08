#include <unistd.h>
void  print_string(const char str[])
{
    char i = 0;
    while (str[i] != '\0')
    {
	i++;
    }
    write(STDOUT_FILENO, str, i);
    return;
}
