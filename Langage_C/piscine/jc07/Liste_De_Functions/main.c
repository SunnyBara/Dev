#include "func.h"
#include "stdio.h"
#include "stdlib.h"

int add5(int n)
{
    return(n+5);
}
s_list * list_addtest(s_list *l)
{
    s_list *tmp;
    int i = 0;
    tmp = l;
    while (i < 5)
    {   
        tmp=list_add(tmp, 5-i);
        i++;
    }
    list_print(tmp);
    return(tmp);
}

s_listf * listf_addtest(s_listf *l)
{
    s_listf *tmp;
    int i = 0;
    tmp = l;
    while (i < 100)
    {   
        tmp=listf_add(tmp, &add5);
        i++;
    }
    listf_print(tmp);
    return(tmp);
}

int main(int argc, char **argv)
{
    s_list *l;
    s_listf *lf;
    funcP func1; 
    funcP func2; 
    func2 = &add5;
    printf(" int = %i\n", (*func2)(5));
    l = list_addtest(l);
    lf = listf_addtest(lf);
    apply(l,lf);
    list_print(l);
    return(0);
}