//最小公倍数 P156
#include <cstdio>
#include <cmath>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int a, b, d, lcm;
    scanf("%d%d", &a, &b);
    d = gcd(a, b);
    lcm = a / d * b;
    printf("%d", lcm);
    return 0;
}