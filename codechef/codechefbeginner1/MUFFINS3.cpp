#include <cstdio>
using namespace std;

struct Solution
{
    void Solve()
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", n / 2 + 1);
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