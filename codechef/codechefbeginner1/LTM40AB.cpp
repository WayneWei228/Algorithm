#include <cstdio>
#include <algorithm>
using namespace std;

struct Solution
{
    void Solve()
    {
        int a, b, c, d;
        long long ans = 0;
        scanf("%d%d%d%d", &a, &b,&c,&d);
        for (int x = a; x <= b; x++) {
            ans += max(0,d-max(x+1,c)+1);
        }
        printf("%lld\n",ans);
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
