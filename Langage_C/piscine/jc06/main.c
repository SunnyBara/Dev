#include "my_str.h"
#include <stdio.h>
#include <stdlib.h>

void my_strupcasetest()
{
    char *str = my_str("foMction 1 avec $s#ace");
    my_strupcase(str);
    printf("str = %s\n",str);
    return;
}


void my_strlowcasetest()
{
    char *str = my_str("foMcTiOn 2 avec $s#ace");
    my_strlowcase(str);
    printf("str = %s\n",str);
    return;
}

void my_strcmptest()
{
   char *str1 = my_str("foMction 1 avec $s#ace");
   char *str2 = my_str("foMc avec $s#ace");
   int ret = my_strcmp(str1, str2);

   if(ret < 0) 
   {
      printf("str1 is less than str2 et ret = %i\n",ret);
   } 
   else if(ret > 0) 
    {
      printf("str2 is less than str1 et ret = %i\n",ret);
    } 
   else
    {
      printf("str1 is equal to str2et ret = %i\n", ret);
    }
   return;
}

void my_strncmptest()
{
   char *str1 = my_str("foMction 1 avec $s#ace");
   char *str2 = my_str("foMc avec $s#ace");
   int ret = my_strncmp(str1, str2, 6);

   if(ret < 0) 
   {
      printf("str1 is less than str2 et ret = %i\n", ret);
   } 
   else if(ret > 0) 
    {
      printf("str2 is less than str1 et ret = %i\n", ret);
    } 
   else
    {
      printf("str1 is equal to str2et ret = %i\n", ret);
    }
   return;
}

void my_strcpytest()
{
    const char *src = "coucou";
    char *dest;
    dest=malloc(my_strlen(src)*sizeof(char));
    my_strcpy(dest, src);
    printf("dest : %s\n", dest);
    return;
}
void my_strncpytest()
{
    const char *src = "coucou";
    char *dest;
    dest=malloc(my_strlen(src)*sizeof(char));
    my_strncpy(dest, src +2, 3);
    printf("dest : %s\n", dest);
    free(dest);
    return;
}

void my_atoitest()
{
    const char *ptr ="     -7844";
    printf("Entier  = %i\n", my_atoi(ptr));
    return;
}
void my_atoibasetest()
{
    const char *str ="-ff";
    printf("Entier  = %i\n", my_atoi_base(str, "0123456789abcdef"));
    return;
}

void my_strtoultest()
{
   char str[30] = "2030300 This is test";
   const char *ptr;
   unsigned long int ret;

   ret = my_strtoul(str, &ptr, 10);
   printf("The number(unsigned long integer) is %lu\n", ret);
   printf("String part is |%s|\n", ptr);
    return;
}
void my_strarraytest()
{
int i =  0;
char **c;
char *str = "asj:/zzdiqdda:/zzz";
c = my_strarray(str,":/");
while (c[i])
{
  printf(" c =%s\n",c[i]);
  i++;
}
return;
}
void my_strstrtest()
{
  const char haystack[20] = "TutorialsPoityyy";
  const char needle[10] = "Point";

 const char *ret = my_strstr(haystack, needle);

  printf("The substring is: %s\n", ret);
  return;
}

void my_strcattest()
{
  char *append=my_str("chenille");
  char *s=my_str("qui redemarre");
  s = my_strcat(s,append);
  printf(" s= %s\n",s);
  return;
}

void my_itoatest()
{
  char str[15];
  int value=1750;
  printf("my_itoa %s\n", my_itoa(value,str,16));
  return;
}

int main(int argc, char  **argv)
{
/*  my_strupcasetest();
    my_strlowcasetest();
    my_strcmptest();
    my_strncmptest();   
    my_strcpytest();
    my_strncpytest();
    my_atoitest();
    my_atoibasetest();
    my_strtoultest();
    my_strarraytest();
    my_strstrtest(); 
    my_strcattest();
  */my_itoatest();
    return(0);
}