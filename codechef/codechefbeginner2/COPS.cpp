#include <cstdio>
#include <vector>
using namespace std;
struct Solution
{
    void Solve()
    {
        vector<bool> check;
        check.resize(100);
        int m, x, y;
        scanf("%d%d%d", &m, &x, &y);
        for (int i = 0; i < m; i++)
        {
            int pos;
            scanf("%d", &pos);
            int start = max(pos - x * y, 1);
            int end = min(pos + x * y, 100);
            for (int j = start; j <= end; j++)
            {
                check[j - 1] = true;
            }
        }
        int cnt = 0;
        for (int i = 0; i < check.size(); i++)
        {
            if (!check[i])
            {
                cnt++;
            }
        }
        printf("%d\n", cnt);
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