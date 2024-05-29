// 大整数减法
#include <cstdio>
#include <cstring>
struct bign
{
    int d[1000];
    int len;
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[]) //低位在前
{
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

bign sub(bign a, bign b)
{
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        if (a.d[i] < b.d[i])
        {
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0)
    {
        c.len--;
    }
    return c;
}

void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i--)
    {
        printf("%d", a.d[i]);
    }
}

int main()
{
    char str1[1000], str2[1000];
    scanf("%s%s", str1, str2);
    bign a = change(str1);
    bign b = change(str2);
    if (a.len > b.len)
    {
        print(sub(a, b));
    }
    else if (a.len < b.len)
    {
        printf("-");
        print(sub(b, a));
    }
    else
    {
        for (int i = a.len - 1; i >= 0; i--)
        {
            if (a.d[i] > b.d[i])
            {
                print(sub(a, b));
                break;
            }
            if (a.d[i] < b.d[i])
            {
                printf("-");
                print(sub(b, a));
                break;
            }
        }
    }
    return 0;
}
