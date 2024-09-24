#include <unistd.h>

void recur(char *plainte, int i)
{
    if (plainte[i] == '\0')
    {
        return;
    }
    write(STDOUT_FILENO, &plainte[i], 1);
    recur(plainte, i + 1);
}

int main()
{
    char *plainte = "ça fait longtemps que j'ai pas codé\n";
    recur(plainte, 0);
    return 0;
}