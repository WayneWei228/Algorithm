#include <algorithm>
#include <cstdio>
#include <limits>
#include <vector>
using namespace std;

typedef long long int64;

struct Solution {
    int N;
    int64 cur = 0;

    void Solve() {
        vector<int> First(7, numeric_limits<int>::max()), Last(7, 0);
        scanf("%d", &N);
        /*
        照道理先做前缀和数组
        然后 % 7 放位置
        */

        First[0] = 0;
        for (int i = 1; i <= N; i++) {
            int x;
            scanf("%d", &x);
            cur += x;
            cur %= 7;
            First[cur] = min(First[cur], i);
            Last[cur] = i;
        }
        int ans = 0;
        for (int i = 0; i < 7; i++) {
            if (First[i] <= N) {
                ans = max(ans, Last[i] - First[i]);
            }
        }
        printf("%d\n", ans);
    }
};

int main() {
    Solution().Solve();
    return 0;
}