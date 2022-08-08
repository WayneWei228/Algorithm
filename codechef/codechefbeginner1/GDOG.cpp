#include <cstdio>
#include <algorithm>
using namespace std;

struct Solution
{
    void Solve()
    {
        int n, k, ans = 0;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= k; i++)
        {
            int temp = n % i;
            ans = max(ans, temp);
        }
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