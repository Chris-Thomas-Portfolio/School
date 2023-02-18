
//extern int asmFunc10(void);
// prototype
int var2(void);
int var3(void);
void main(void)
{
    int i = 10;
    int j = 20;
    i = var2();
    j = var3();
}
int var2(void)
{
    int i = 10;
    int j = 20;
    for (i=5; i>0; i--)
    {
        j++;
    }
    return (j);
}
int var3(void)
{
    int i = 10;
    int j = 20;
    int k = 30;
    for (i=5; i>0; i--)
    {
        j = j + k;
    }
    return (j);
}

