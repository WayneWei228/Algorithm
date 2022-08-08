#include <cstdio>
#include <algorithm>
using namespace std;

struct Solution
{
    void Solve()
    {
        int r, x1, y1, x2, y2, x3, y3, cnt = 0;
        scanf("%d", &r);
        scanf("%d%d", &x1, &y1);
        scanf("%d%d", &x2, &y2);
        scanf("%d%d", &x3, &y3);
        if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r * r)
        {
            cnt++;
        }
        if ((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) <= r * r)
        {
            cnt++;
        }
        if ((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) <= r * r)
        {
            cnt++;
        }
        if (cnt >= 2)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
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