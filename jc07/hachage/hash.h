typedef struct hash_slot 
{
    char             *elt;
    struct hash_slot *next;
}s_hash_slot;

typedef struct hash 
{
    s_hash_slot **slot;
    unsigned int size;  
}s_hash;
s_hash *hash_new(unsigned int size);
s_hash *hash_insert(s_hash *hash, char *data);
void hash_dump(s_hash *hash);
char *my_itoa(int value, char *str, int base);