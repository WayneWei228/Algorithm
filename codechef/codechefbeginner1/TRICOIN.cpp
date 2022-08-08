#include <cstdio>
#include <algorithm>
using namespace std;

// struct Solution
// {
//     void Solve()
//     {
//         int n, h = 0, cnt = 0;
//         scanf("%d", &n);
//         for (int i = 1;; i++)
//         {
//             if (cnt + i <= n)
//             {
//                 h++;
//                 cnt += i;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         printf("%d\n", h);
//     }
// };


struct Solution
{
    void Solve()
    {
        int n, level = 0;
        scanf("%d", &n);
        while(level + 1 <= n) n -= ++ level;
        printf("%d\n", level);
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