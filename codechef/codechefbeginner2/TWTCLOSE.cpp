#include <cstdio>
#include <vector>
#include <string>
using namespace std;

char Buffer[80];
struct Solution
{
    int N, K;
    vector<bool> Ans;
    void Solve()
    {
        int cnt = 0;
        scanf("%d%d", &N, &K);
        Ans.resize(N);
        for (int i = 0; i < K; i++)
        {
            scanf("%s", Buffer);
            string s = Buffer;
            if (s == "CLICK")
            {   
                int num;
                scanf("%d", &num);
                if (Ans[num - 1])
                {
                    Ans[num - 1] = false;
                    cnt--;
                }
                else
                {
                    Ans[num - 1] = true;
                    cnt++;
                }
            }
            else
            {
                for (int i = 0; i < Ans.size(); i++)
                {
                    Ans[i] = false;
                }
                cnt = 0;
            }
            printf("%d\n",cnt);
        }
    }
};

int main()
{
    Solution().Solve();
    return 0;
}