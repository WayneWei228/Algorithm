#include <cstdio>
#include <vector>
#include <string>
using namespace std;

char Buffer[80];

struct Solution
{
    void Solve()
    {
        bool ans = true;
        scanf("%s",Buffer);
        string x = Buffer;
        scanf("%s",Buffer);
        string y = Buffer;
        for (int i = 0;i < x.size(); i++){
            if (x[i] != y[i] && x[i] != '?' && y[i] != '?'){
                ans = false;
                break;
            }
        }
        if(ans) {
            printf("Yes\n");
        }else
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