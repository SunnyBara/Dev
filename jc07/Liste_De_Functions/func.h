#include  "list.h"
typedef int (*funcP)(int);
typedef struct listf
{
    funcP func;
    struct listf *next;
} s_listf;
s_listf *listf_add(s_listf *l,funcP e);
void listf_print(s_listf *l);
s_listf *listf_find(s_listf *l, funcP e);
s_listf* listf_remove(s_listf *l, funcP e);
s_listf *listf_sorted_add(s_listf *l, funcP e);
void apply(s_list *l, s_listf *lf);

