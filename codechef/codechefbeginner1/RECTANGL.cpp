#include <cstdio>
using namespace std;

struct Solution
{
    void Solve()
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a == b && c == d || a == c && b == d || a == d && b == c)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
};

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        Solution().Solve();
    return 0;
}