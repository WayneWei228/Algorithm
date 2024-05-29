//高精度与低精度的乘法
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

bign change(char str[])
{
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

bign multi(bign a, int b)
{
    bign c;
    int carry = 0; //进位
    for (int i = 0; i < a.len; i++)
    {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10; //个位作为该位结果
        carry = temp / 10;        // 高位部分作为新的进位
    }
    while (carry != 0) // 乘法进位可能不止一位，因此用while
    {
        c.d[c.len++] = carry % 10;
        carry /= 10;
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
    int b;
    char str[1000];
    scanf("%s%d", str, &b);
    bign a = change(str);
    print(multi(a, b));
}