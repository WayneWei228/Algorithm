#include <cstdio>
using namespace std;

struct Solution
{
    void Solve()
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a < b)
        {
            printf("<\n");
        }
        else if (a > b)
        {
            printf(">\n");
        }
        else
        {
            printf("=\n");
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