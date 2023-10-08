typedef struct puissance
{
    int puissance;
} s_puissance;

typedef struct nombres
{
    char value;
    s_puissance *puissances;
    struct nombres *next;
} s_nombres;
int is_abr(char **argv, int argc);
