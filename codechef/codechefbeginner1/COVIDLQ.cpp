#include <cstdio>
using namespace std;
struct Solution
{
    void Solve()
    {
        bool ans = true;
        int n, last = -10;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            if (num == 1)
            {
                if (i - last < 6)
                {
                    ans = false;
                }
                last = i;
            }
        }
        if (ans)
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