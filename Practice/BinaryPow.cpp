#include <cstdio>
typedef long long LL;

//求 a^b % m， 递归写法

LL binaryPow(LL a, LL b, LL m)
{
    if (b == 0)
        return 1;
    if (b % 2 == 1)
    {
        return a * binaryPow(a, b - 1, m) % m;
    }
    else
    {
        LL mul = binaryPow(a, b / 2, m);
        return mul * mul % m;
    }
}

int main()
{
    int a, b, m, ans;
    scanf("%d%d%d", &a, &b, &m);
    ans = binaryPow(a, b, m);
    printf("%d\n", ans);
}
