int mystrlen(const char *s)
{
    char i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return(i);
}