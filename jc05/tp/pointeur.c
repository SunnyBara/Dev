void test(int a, int b, int c, int d)
{
    int r;
    int *addr;
    r = ((b * c) << a) - a;
    addr = &d;
    addr[0] = r;
    return;
}

int main(void)
{
    int a = 2;
    int b = 3;
    int c = 4;
    int r;
    test(a, b, c, r);
    return(r);
}