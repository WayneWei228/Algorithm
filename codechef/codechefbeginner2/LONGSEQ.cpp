#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

char Buffer[10000000];

struct Solution
{
    void Solve()
    {
        int zero = 0, one = 0;
        scanf("%s", Buffer);
        string s = Buffer;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        if (zero == 1 || one == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
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