#include <stdlib.h>
#include <stdio.h>

int my_strlen(char *str);

char *fill_str(char *str, int size)
{
    int i = 0;
    while (i < size)
    {
        str[i] = '0';
        i++;
    }
    return str;
}

char *outer_str(char *s, int numRows, int sizeStr)
{
    char *zigZag = malloc(sizeStr * sizeof(char));
    zigZag = fill_str(zigZag, sizeStr);
    int i = 0;
    int k = 0;
    int l = numRows - 1;
    int incrementation = 2 * numRows - 2;
    int j = 0;
    while (j * incrementation + l < sizeStr)
    {
        j++;
    }
    j = sizeStr - j;
    while (l < sizeStr || k < sizeStr)
    {
        if (k < sizeStr)
        {
            zigZag[i] = s[k];
            k += incrementation;
            i++;
        }
        if (j < sizeStr && l < sizeStr)
        {
            zigZag[j] = s[l];
            l += incrementation;
            j++;
        }
    }
    return (zigZag);
}

char *inner_str(char *s, char *zigZag, int numRows, int sizeStr)
{
    int initposInStr = 1;
    int i = 0;
    int ecart = 0;
    int initposInZigZag = sizeStr / numRows;
    int j = initposInZigZag;
    int maxValue = numRows - 1;
    while (initposInStr < maxValue)
    {
        ecart = 2 * (numRows - 1 - initposInStr);
        i = initposInStr;
        while (i < sizeStr)
        {
            zigZag[j] = s[i];
            j++;
            if (i + ecart < sizeStr)
            {
                zigZag[j] = s[i + ecart];
                j++;
            }
            i += numRows + maxValue - 1;
        }
        initposInStr++;
    }
    return (zigZag);
}
char *convert(char *s, int numRows)
{
    char *respond = s;
    if (numRows > 1)
    {
        int sizeStr = my_strlen(s);
        char *zigZag = outer_str(s, numRows, sizeStr);
        if (numRows > 2)
        {
            zigZag = inner_str(s, zigZag, numRows, sizeStr);
        }
        respond = zigZag;
    }

    return (respond);
}