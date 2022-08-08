#include <cstdio>
using namespace std;

struct Solution
{
    void Solve()
    {
        double h, c, t;
        scanf("%lf%lf%lf", &h, &c, &t);
        bool c1 = (h > 50);
        bool c2 = (c < 0.7);
        bool c3 = (t > 5600);
        if (c1 && c2 && c3)
        {
            printf("10\n");
        }
        else if (c1 && c2)
        {
            printf("9\n");
        }
        else if (c2 && c3)
        {
            printf("8\n");
        }
        else if (c1 && c3)
        {
            printf("7\n");
        }
        else if (c1 || c2 || c3)
        {
            printf("6\n");
        }
        else
        {
            printf("5\n");
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