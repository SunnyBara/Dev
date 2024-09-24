#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <unistd.h>

int hash_function(char *key, int hash_size)
{
    int index = 0;
    int i = 0;
    while (key[i] != '\0')
    {
        index += key[i] - 'a' + 1;
        i += 1;
    }
    index += i;
    return (index % hash_size);
}

s_hash *new_hash(unsigned int size)
{
    s_hash *newhash = malloc(sizeof(s_hash));
    newhash->size = size;
    newhash->slots = malloc(size * sizeof(s_hash_slot *));
    return newhash;
}

s_hash_slot *create_slot(char *data)
{
    s_hash_slot *newslot = malloc(sizeof(s_hash_slot));
    newslot->elt = data;
    newslot->next = NULL;
    return newslot;
}

s_hash *add_elem(s_hash *hash, int index, char *data)
{
    s_hash_slot *slot = create_slot(data);
    if (hash->slots[index] != NULL)
    {
        s_hash_slot *tmp = hash->slots[index];
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = slot;
    }
    else
    {
        hash->slots[index] = slot;
    }
    return hash;
}

s_hash *hash_insert(s_hash *hash, char *data)
{
    int index = hash_function(data, hash->size);
    hash = add_elem(hash, index, data);
    return hash;
}

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i += 1;
    }
    return i;
}

void write_elem(char *elt, int size)
{
    write(STDOUT_FILENO, elt, size);
}

void dump_value(s_hash_slot *slot_to_dump)
{
    if (slot_to_dump->elt != NULL)
    {
        s_hash_slot *tmp = slot_to_dump;
        write_elem(" = ", 4);
        write_elem(tmp->elt, my_strlen(tmp->elt));
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            write_elem(" -> ", 4);
            write_elem(tmp->elt, my_strlen(tmp->elt));
        }
    }
    write_elem("\n", 1);
    return;
}

void hash_dump(s_hash *hash)
{
    int i = 0;
    while (i < hash->size)
    {
        if (hash->slots[i] != NULL)
        {
            int mallocsize = 1;
            write_elem("[Key", 5);
            if (i > 9)
            {
                mallocsize = 2;
            }
            char *key_number = malloc(sizeof(char) * mallocsize);
            key_number[0] = i + '0';
            write_elem(key_number, mallocsize);
            write_elem("]", 1);
            dump_value(hash->slots[i]);
        }
        i += 1;
    }
}

int main(void)
{
    unsigned int size = 8;
    s_hash *hash = new_hash(size);
    hash = hash_insert(hash, "test");
    hash = hash_insert(hash, "a");
    hash = hash_insert(hash, "test");
    hash_dump(hash);
    return 0;
}