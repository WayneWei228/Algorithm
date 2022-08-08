#include <cstdio>
using namespace std;

struct Solution
{
    int N, K;

    void Solve() {
        scanf("%d%d", &N, &K);
        int cnt = 0;
        for (int i = 0; i < N; i++){
            int t;
            scanf("%d", &t);
            if (t % K == 0) cnt++;
        }
        printf("%d\n",cnt);
    }
};


int main() {
    Solution().Solve();
    return 0;
}