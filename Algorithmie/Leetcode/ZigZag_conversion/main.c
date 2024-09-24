#include <stdio.h>
char *convert(char *s, int numRows);

int main(void)
{
    char *s = "PAYPALISHIRING";
    printf("%s\n", convert(s, 3));
    return 0;
}