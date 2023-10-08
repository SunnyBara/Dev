
#include "hash.h"
char *base2(int value, char *str)
{
    int chiffre = value;
    int i = 0;
    int puissance = 1;
    int j = 1;
    int save = 0;
    while ( value/puissance > 2)
    {
        puissance = puissance *2;
        j++;
    }
    while( j > 0)
    {
        str[i] = ((value-save)/puissance)+48;
        save = (value/puissance)*puissance;
        puissance = puissance/2;
        j--;
        i++;
    }
return(str);
}

char *base10(int value, char *str)
{
    int chiffre = value;
    int i = 0;
    int puissance = 1;
    int j = 1;
    int save = 0;
    if (value < 0)
    {
        str[i] = '-';
        i++;
    }
    while ( value/puissance > 9)
    {
        puissance = puissance *10;
        j++;
    }
    while( j > 0)
    {
        str[i] = ((value-save)/puissance)+48;
        save = (value/puissance)*puissance;
        puissance = puissance/10;
        j--;
        i++;
    }
    return(str);
}

char *base16(int value,char *str)
{
    int chiffre = value;
    int i = 0;
    int puissance = 1;
    int j = 1;
    int save = 0;
    int ascii = 0;
    if (value < 0)
    {
        str[i] = '-';
        i++;
    }
    while ( value/puissance > 15)
    {
        puissance = puissance *16;
        j++;
    }
    while( j > 0)
    {
        ascii = ((value-save)/puissance);
        if (ascii < 10)
        {
            str[i] = ascii +48;
        }
        else if (ascii > 9)
        {
            str[i] = ascii +55;
        }
        save = (value/puissance)*puissance;
        puissance = puissance/16;
        j--;
        i++;
    }
    return(str);
}
char *my_itoa(int value, char *str, int base)
{
    if (base == 2)
    {
        base2(value,str);
    }
    if (base == 10)
    {
        str = base10(value,str);
    }
    if (base == 16)
    {
        base16(value,str);
    }
    return (str);
}