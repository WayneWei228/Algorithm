#include <cstdio>
using namespace std;

struct Solution
{

    void Solve()
    {
        int n, even = 0, odd = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            if (x % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        if (even > odd)
        {
            printf("READY FOR BATTLE\n");
        }
        else
        {
            printf("NOT READY\n");
        }
    }
};

int main()
{
    Solution().Solve();
    return 0;
}