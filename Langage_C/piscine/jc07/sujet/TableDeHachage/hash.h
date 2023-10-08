typedef unsigned int (*f_hash)(const void *data);
typedef int (*f_cmp)(const void *,const void *);
typedef void (*f_display)(const void *);
typedef void (*f_free)(void *);

typedef struct hash_slot
{
    void *elt;
    struct hash_slot *next;
}s_hash_slot;

typedef struct hash 
{
    s_hash_slot **slot;
    f_hash       funch;
    unsigned int  size;  
}s_hash;

int hash_print_key(const s_hash *hash, const void *data);
void hash_delete(s_hash *hash);
s_hash *hash_new(unsigned int size, f_hash hfunc);
unsigned int my_hashfunc(const void *data);
char *my_itoa(int value, char *str, int base);
int my_strlen(const char *str);
void  my_display(const void *data);
void hash_dump(const s_hash *hash, f_display display);
int hash_insert(s_hash *hash, void *data);
int hash_count(const s_hash *hash, const void *data, f_cmp my_cmp);
int my_cmp(const  void *data, const void* );
int hash_count(const s_hash *hash, const void *data, f_cmp my_cmp);
int my_cmp(const void *data, const void *elt);