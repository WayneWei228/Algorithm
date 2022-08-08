#include <cstdio>
#include <algorithm>
using namespace std;

struct Solution
{
    void Solve()
    {
        int a, b, n;
        scanf("%d%d%d", &a, &b, &n);
        if (n % 2 != 0)
        {
            a *= 2;
        }
        int ans = max(a, b) / min(a, b);
        printf("%d\n", ans);
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