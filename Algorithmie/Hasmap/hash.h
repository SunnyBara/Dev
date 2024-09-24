typedef struct hash_slot
{
    char *elt;
    struct hash_slot *next;
} s_hash_slot;

typedef struct hash
{
    s_hash_slot **slots;
    unsigned int size;
} s_hash;
