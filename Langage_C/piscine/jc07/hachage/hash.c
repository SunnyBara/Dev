#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int hash_function(char *elt, int hash_size)
{
    int i = 0;
    int cle = 0;
    for (i = 0; elt[i] != '\0'; i++)
        cle += elt[i];
    cle += i;
    return (cle % hash_size);
}

s_hash *hash_new(unsigned int size)
{
    s_hash *f = malloc(sizeof(s_hash));
    s_hash_slot **s = malloc(size * sizeof(s_hash_slot *));
    f->slot = s;
    f->size = size;
    return (f);
}

s_hash *hash_insert(s_hash *hash, char *data)
{
    s_hash_slot *slot;
    int cle;
    cle = hash_function(data, hash->size);
    slot = malloc(sizeof(s_hash_slot));
    slot->elt = data;
    if (hash->slot[cle] == NULL)
    {
        hash->slot[cle] = slot;
    }
    else
    {
        slot->next = hash->slot[cle];
        hash->slot[cle] = slot;
    }
    return (hash);
}

void hash_dump(s_hash *hash)
{
    int i = 0;
    s_hash_slot *tmp;
    while (i < hash->size)
    {
        tmp = hash->slot[i];
        while (tmp != NULL)
        {

            printf("%s", tmp->elt);
            tmp = tmp->next;
            if (tmp != NULL)
            {
                printf(" ");
            }
        }
        printf("\n");
        i++;
    }
    return;
}
