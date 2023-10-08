#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <unistd.h>

int my_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}
unsigned int my_hashfunc(const void *data)
{
    char *str;
    str = (char *)data;
    return (my_strlen(str));
}

s_hash *hash_new(unsigned int size, f_hash hfunc)
{
    s_hash *l;
    s_hash_slot **s;
    l = malloc(sizeof(s_hash));
    s = malloc(size * sizeof(s_hash_slot *));
    l->funch = hfunc;
    l->size = size;
    l->slot = s;
    return (l);
}

void hash_delete(s_hash *hash)
{
    int i = 0;
    while (i < hash->size)
    {
        free(hash->slot[i]);
        i++;
    }
    free(hash->slot);
    free(hash);
    return;
}

int hash_print_key(const s_hash *hash, const void *data)
{
    char *str;
    str = malloc(sizeof(char));
    write(STDOUT_FILENO, my_itoa(hash->funch(data) % hash->size, str, 10), 1);
    write(STDOUT_FILENO, "\n", 1);
    return (0);
}

int hash_insert(s_hash *hash, void *data)
{
    unsigned int position;
    position = hash->funch(data) % hash->size;
    int i = 0;
    s_hash_slot *tmp;
    tmp = malloc(sizeof(s_hash_slot));
    tmp->elt = data;
    if (hash->slot[position] != NULL)
    {
        tmp->next = hash->slot[position];
    }
    hash->slot[position] = tmp;
    return (0);
}

void my_display(const void *data)
{
    char *str;
    str = (char *)data;
    write(STDOUT_FILENO, str, my_strlen(str));
    return;
}

void hash_dump(const s_hash *hash, f_display display)
{
    int i = 0;
    s_hash_slot *tmp;
    while (i < hash->size)
    {
        tmp = hash->slot[i];
        if (tmp != NULL)
        {
            my_display(tmp->elt);
        }
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            write(STDOUT_FILENO, " ", 1);
            my_display(tmp->elt);
        }
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
    return;
}
int my_cmp(const void *data, const void *elt)
{
    char *mydata;
    char *myelt;
    mydata = (char *)data;
    myelt = (char *)elt;
    int i = 0;
    int cpt = 0;
    int sizedata = my_strlen(mydata);
    int sizeelt = my_strlen(myelt);
    if (sizeelt == sizedata)
    {
        while (mydata[i] == myelt[i] && i < sizedata)
        {
            i++;
        }
        if (mydata[i] == '\0')
        {
            cpt = 1;
        }
    }

    return (cpt);
}

int hash_count(const s_hash *hash, const void *data, f_cmp my_cmp)
{
    int i = 0;
    int cpt = 0;
    s_hash_slot *tmp;
    while (i < hash->size)
    {
        tmp = hash->slot[i];
        if (tmp != NULL)
        {
            cpt = cpt + my_cmp(data, tmp->elt);
        }
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            cpt = cpt + my_cmp(data, tmp->elt);
        }
        i++;
    }
    return (cpt);
}