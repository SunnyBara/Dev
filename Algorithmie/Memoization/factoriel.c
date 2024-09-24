#include <stdio.h>
#include <stdlib.h>

typedef struct memo_table
{
    int value;
    struct memo_table *next;
} s_mem_table;

typedef struct info_table
{
    int size;
    struct memo_table *first_eleme;
    struct memo_table *last_elem;
} s_info_table;

s_mem_table *init_meme_table()
{
    s_mem_table *new_memtable = malloc(sizeof(s_mem_table));
    new_memtable->next = NULL;
    new_memtable->value = 1;
    return new_memtable;
}

s_mem_table *add_to_mem_table(s_mem_table *last_elem, int value)
{
    s_mem_table *new_elem = malloc(sizeof(s_mem_table));
    new_elem->next = NULL;
    new_elem->value = value;
    last_elem->next = new_elem;
    return new_elem;
}

s_info_table *init_info_table()
{
    s_info_table *info_table = malloc(sizeof(s_info_table));
    info_table->first_eleme = init_meme_table();
    info_table->last_elem = info_table->first_eleme;
    info_table->size = 1;
    return info_table;
}
int factoriel(int n, s_info_table *info_table)
{
    if (n == 0)
    {
        return 1;
    }
    else if (info_table->size > n)
    {
        return info_table->first_eleme[n].value;
    }
    else
    {
        int value = factoriel(n - 1, info_table) * n;
        add_to_mem_table(info_table->first_eleme, value);
        info_table->size += 1;
        return value;
    }
}

int main(int argc, char **argv)
{
    s_info_table *info_table = init_info_table();
    int i = 0;
    while (i < 500000)
    {
        factoriel(5000, info_table);
        i++;
    }
    return 0;
}