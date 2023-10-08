#ifndef DLIST_H_
#define DLIST_H_
#include <stdlib.h>
typedef int (*f_cmp)(const void *elt1, const void *elt2);
typedef void *(*f_copy)(const void *elt);
typedef void (*f_apply)(void *elt, void *arg);
typedef void (*f_free)(void *elt);

typedef struct dlist_item
{
  struct dlist_item *next;
  struct dlist_item *prev;
  void *data;
} s_dlist_item;

typedef struct dlist
{
  s_dlist_item *head;
  s_dlist_item *tail;
  f_free ffree;
  f_copy fcopy;
  f_cmp fcmp;
  size_t size;
} s_dlist;
void dlist_init(s_dlist *list, f_free ffree, f_copy fcopy, f_cmp fcmp);
void dlist_show_string(s_dlist *list);
size_t dlist_get_size(s_dlist *list);
int dlist_add_head(s_dlist *list, void *elt);
int dlist_add_queue(s_dlist *list, void *elt);
int dlist_add_index(s_dlist *list, void *elt, size_t index);
int dlist_add(s_dlist *list, void *elt);
const void *dlist_get(s_dlist *list, size_t index);
const void *dlist_find(s_dlist *list, const void *elt, f_cmp fcmp);
void *dlist_copy_elt(s_dlist *list, const void *elt);
void *dlist_remove(s_dlist *list, size_t index);
void *dlist_remove_eq(s_dlist *list, void *elt, f_cmp fcmp);
void dlist_free(s_dlist *list);
void dlist_concat(s_dlist *list1, s_dlist *list2);
void dlist_rev(s_dlist *list);
void dlist_shift(s_dlist *list, int decal);
void dlist_map(s_dlist *list, f_apply fapply, void *arg);
s_dlist *dlist_copy(s_dlist *list);
s_dlist *dlist_split_at(s_dlist *list, size_t index);
void dlist_merge(s_dlist *list1, s_dlist *list2);
void dlist_sort(s_dlist *list1, f_cmp ffcmp);
void dlist_set_cmp_function(s_dlist *list, f_cmp fcmp);
#endif

int my_cmpchar(const void *elt1, const void *elt2);
void *my_fcopychar(const void *elt);
void myf_free(void *elt);