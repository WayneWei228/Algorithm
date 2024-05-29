//最大公约数 P154
#include <cstdio>
#include <cmath>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     printf("%d", gcd(a, b));
//     return 0;
// }

int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        printf("%d\n", gcd(m, n));
    }
    return 0;
}