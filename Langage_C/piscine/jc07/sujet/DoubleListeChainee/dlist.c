#include "dlist.h"
#include <unistd.h>

int my_cmpchar(const void *elt1, const void *elt2)
{
    char *Elt1 = (char *)elt1;
    char *Elt2 = (char *)elt2;
    int i = 0;
    int j = 0;
    int Selt1 = 0;
    int Selt2 = 0;
    int returned = 0;
    while (Elt1[i] != '\0')
    {
        Selt1 = Selt1 + Elt1[i];
        i++;
    }
    while (Elt2[j] != '\0')
    {
        Selt2 = Selt2 + Elt2[j];
        j++;
    }
    if (Selt1 > Selt2)
    {
        returned = 1;
    }

    else if (Selt2 > Selt1)
    {
        returned = -1;
    }
    return (returned);
}
void *my_fcopychar(const void *elt)
{
    char *elt1 = (char *)elt;
    int size;
    int i = 0;
    while (elt1[i] != '\0')
    {
        i++;
    }
    size = i;
    i = 0;
    char *eltcopy;
    eltcopy = malloc(size * sizeof(char));
    while (i < size)
    {
        eltcopy[i] = elt1[i];
        i++;
    }
    return (eltcopy);
}
void myf_free(void *elt)
{
    free(elt);
    return;
}
void dlist_init(s_dlist *list, f_free ffree, f_copy fcopy, f_cmp fcmp)
{
    list->fcmp = fcmp;
    list->ffree = ffree;
    list->fcopy = fcopy;
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return;
}
size_t dlist_get_size(s_dlist *list)
{
    return (list->size);
}
void wrt(void *elt)
{
    int i = 0;
    char *writ;
    writ = (char *)elt;
    while (writ[i] != '\0')
    {
        i++;
    }
    write(STDOUT_FILENO, writ, i);
    return;
}
void dlist_show_string(s_dlist *list)
{
    s_dlist_item *tmp;
    tmp = list->head;
    while (tmp != NULL)
    {
        wrt(tmp->data);
        write(STDOUT_FILENO, "\n", 1);
        tmp = tmp->next;
    }
    return;
}
int dlist_add_head(s_dlist *list, void *elt)
{
    s_dlist_item *tmp;
    tmp = malloc(sizeof(s_dlist_item));
    tmp->data = elt;
    if (list->head != NULL)
    {
        tmp->next = list->head;
        list->head->prev = tmp;
    }
    if (list->tail != NULL && list->tail->prev == NULL)
    {
        list->tail->prev = tmp;
        tmp->next = list->tail;
    }
    list->head = tmp;
    list->size = list->size + 1;
    return (0);
}
int dlist_add_queue(s_dlist *list, void *elt)
{
    s_dlist_item *tmp;
    tmp = malloc(sizeof(s_dlist_item));
    tmp->data = elt;
    if (list->tail != NULL)
    {
        tmp->prev = list->tail;
        list->tail->next = tmp;
    }
    if (list->head != NULL && list->head->next == NULL)
    {
        list->head->next = tmp;
        tmp->prev = list->head;
    }
    list->tail = tmp;
    list->size = list->size + 1;
    return (0);
}
int dlist_add_index(s_dlist *list, void *elt, size_t index)
{
    int i = 1;
    list->size = list->size + 1;
    if (list->size < index)
    {
        return (0);
    }
    s_dlist_item *tmp;
    s_dlist_item *insert;
    insert = malloc(sizeof(s_dlist_item));
    insert->data = elt;
    tmp = list->head;
    if (index == 0)
    {
        dlist_add_head(list, elt);
        list->size = list->size - 1;
        return (1);
    }
    if (index == list->size)
    {
        dlist_add_queue(list, elt);
        list->size = list->size - 1;
        return (1);
    }

    while (i < index)
    {
        tmp = tmp->next;
        i++;
    }
    if (tmp->next != NULL)
    {
        insert->next = tmp->next;
        tmp->next->prev = insert;
    }
    if (tmp->prev != NULL)
    {
        insert->next = tmp->next;
    }
    tmp->next = insert;
    insert->prev = tmp;
    return (1);
}
int dlist_add(s_dlist *list, void *elt)
{
    list->size = list->size + 1;
    s_dlist_item *insert;
    insert = malloc(sizeof(s_dlist_item));
    insert->data = elt;
    if (list->fcmp != NULL)
    {
        s_dlist_item *tmp;
        tmp = list->head;
        if (list->fcmp(list->head->data, insert->data) == 1)
        {
            dlist_add_head(list, insert->data);
            list->size = list->size - 1;
            return (1);
        }
        while (tmp != NULL && list->fcmp(insert->data, tmp->data) == 1)
        {
            tmp = tmp->next;
        }
        if (tmp == NULL)
        {
            dlist_add_queue(list, insert->data);
            list->size = list->size - 1;
            return (1);
        }
        insert->next = tmp;
        insert->prev = tmp->prev;
        tmp->prev = insert;
    }
    return (1);
}
const void *dlist_get(s_dlist *list, size_t index)
{
    int i = 0;
    if (list->size < index)
    {
        return (NULL);
    }
    s_dlist_item *tmp;
    tmp = list->head;
    while (i < index)
    {
        tmp = tmp->next;
        i++;
    }
    return (tmp->data);
}
const void *dlist_find(s_dlist *list, const void *elt, f_cmp fcmp)
{
    s_dlist_item *find;
    find = list->head;
    while (list->fcmp(elt, find->data) != 0 && find != NULL)
    {
        find = find->next;
    }
    if (find != NULL)
    {
        return (find);
    }
    return (NULL);
}

void *dlist_copy_elt(s_dlist *list, const void *elt)
{
    return (list->fcopy(elt));
}

void *dlist_remove(s_dlist *list, size_t index)
{
    s_dlist_item *tmp;
    int i = 0;
    if (index > list->size)
    {
        return (NULL);
    }
    if (index > list->size / 2)
    {
        tmp = list->head;
        while (i < index)
        {
            tmp = tmp->next;
            i++;
        }
    }
    else
    {
        tmp = list->tail;
        while (i < (list->size - index))
        {
            tmp = tmp->prev;
            i++;
        }
    }
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
    return (list);
}

void *dlist_remove_eq(s_dlist *list, void *elt, f_cmp cmp)
{
    s_dlist_item *find;
    void *save;
    find = list->head;
    if (cmp == NULL)
    {
        cmp = list->fcmp;
    }
    while (find != NULL && cmp(find->data, elt) != 0)
    {
        find = find->next;
    }
    if (find == NULL)
    {
        return (NULL);
    }
    save = find->data;
    find->prev->next = find->next;
    find->next->prev = find->prev;
    return (save);
}

void dlist_free(s_dlist *list)
{
    s_dlist_item *tmp;
    tmp = list->head;
    s_dlist_item *save;
    while (tmp != NULL)
    {
        save = tmp;
        tmp = tmp->next;
        free(save->prev);
        free(save->next);
        free(save->data);
        free(save);
    }
    free(list);
    return;
}
void dlist_concat(s_dlist *list1, s_dlist *list2)
{
    list1->tail->next = list2->head;
    list1->tail = list2->tail;
    list2->tail = NULL;
    list2->head = NULL;
    dlist_free(list2);
    return;
}
void dlist_rev(s_dlist *list)
{
    s_dlist_item *save1;
    s_dlist_item *save2;
    s_dlist_item *tmp;
    int i = 0;
    tmp = list->tail;
    list->head = tmp;
    while (i < list->size)
    {
        save1 = tmp;
        tmp = tmp->prev;
        save2 = save1;
        save1->next = save1->prev;
        save1->prev = save2->next;
        i++;
    }
    list->tail = tmp;
}
void dlist_shift(s_dlist *list, int decal)
{
    if (decal == 0)
    {
        return;
    }
    decal = (decal % list->size);
    s_dlist_item *tmp;
    s_dlist_item *tmpp;
    int i = 0;
    list->head->prev = list->tail;
    list->tail->next = list->head;
    if (decal < 0)
    {
        decal = decal * -1;
        tmp = list->head;
        while (i < decal - 1)
        {
            tmp = tmp->next;
            i++;
        }
        tmpp = tmp->next;
        tmp->next = NULL;
        tmpp->prev = NULL;
        list->head = tmpp;
        list->tail = tmp;
    }
    else
    {
        tmp = list->tail;
        while (i < decal - 1)
        {
            tmp = tmp->prev;
            i++;
        }
        tmpp = tmp->prev;
        tmpp->next = NULL;
        tmp->prev = NULL;
        list->head = tmp;
        list->tail = tmpp;
    }
    return;
}
void dlist_map(s_dlist *list, f_apply fapply, void *arg)
{
    s_dlist_item *tmp;
    tmp = list->head;
    while (tmp != NULL)
    {
        fapply(tmp->data, arg);
        tmp = tmp->next;
    }
    return;
}

s_dlist *dlist_copy(s_dlist *list)
{
    int i = 0;
    s_dlist_item *tmp;
    tmp = list->head->next;
    s_dlist *list2;
    dlist_init(list2, list->ffree, list->fcopy, list->fcmp);
    dlist_add_head(list2, list->head->data);
    while (tmp != list->tail)
    {
        dlist_add(list2, tmp->data);
        tmp = tmp->next;
    }
    dlist_add_queue(list2, list->tail->data);
    return (list2);
}
s_dlist *dlist_split_at(s_dlist *list, size_t index)
{
    int i = 0;
    s_dlist *save;
    s_dlist_item *tmp;
    tmp = list->head;
    while (i < index)
    {
        tmp = tmp->next;
        i++;
    }
    save->head = tmp;
    save->head->prev = NULL;
    save->tail = list->tail;
    save->size = list->size - index;
    list->tail = tmp;
    list->size = index;
    tmp->next = NULL;
    return (save);
}
void dlistemerge(s_dlist *list1, s_dlist *list2)
{
    int i = 0;
    s_dlist_item *tmp;
    s_dlist_item *tmp2;
    s_dlist_item *savetmp2;
    s_dlist_item *savetmp;
    tmp = list2->head;
    if (list1->fcmp == NULL && list2->fcmp == NULL)
    {
        list1->tail->next = list2->head;
        list2->head->prev = list1->tail;
        list1->tail = list2->tail;
        return;
    }
    else if (list1->fcmp == NULL && list2->fcmp != NULL)
    {
        list1->fcmp = list2->fcmp;
    }
    while (tmp2 != NULL)
    {
        tmp = list1->head;
        savetmp2 = tmp2;
        if (list1->fcmp(list1->head->data, tmp2->data) >= 0)
        {

            tmp2->prev = NULL;
            tmp2->next = list1->head;
            list1->head->prev = tmp2;
            list1->head = tmp2;
        }
        else
        {
            while (tmp != NULL && list1->fcmp(tmp->data, tmp2->data) < 0)
            {
                tmp = tmp->next;
            }
            if (tmp == NULL)
            {
                tmp2->next = NULL;
                tmp2->prev = list1->tail;
                list1->tail->next = tmp2;
                list1->tail = tmp2;
            }
            else
            {
                tmp2->prev = tmp->prev;
                tmp->prev = tmp2;
                tmp2->next = tmp;
            }
        }
        tmp2 = savetmp2->next;
    }
    return;
}

void dlist_sort(s_dlist *list, f_cmp fcmp)
{
    s_dlist_item *tmp;
    tmp = list->head;
    int size = list->size;
    int i = 0;
    int j = 0;
    void *compare = tmp->data;
    void *savedata;
    while (j < list->size)
    {
        while (i < size)
        {
            if (fcmp(compare, tmp->data) < 1)
            {
                savedata = compare;
                compare = tmp->data;
                tmp->data = savedata;
            }
            tmp = tmp->next;
            i++;
        }
        tmp->data = compare;
        size--;
        i = 0;
        j++;
        tmp = list->head;
    }
}

void dlist_set_cmp_function(s_dlist *list, f_cmp cmp)
{
    list->fcmp = cmp;
    return;
}