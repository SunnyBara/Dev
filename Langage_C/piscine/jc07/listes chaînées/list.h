typedef struct list
{
    int data;
    struct list *next;
} s_list;
s_list *list_add(s_list *l,int e);
void list_print(s_list *l);
s_list *list_find(s_list *l, int e);
s_list* list_remove(s_list *l, int e);
s_list *list_sorted_add(s_list *l, int e);



