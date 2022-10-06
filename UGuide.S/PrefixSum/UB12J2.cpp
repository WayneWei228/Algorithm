#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Solution {
    int N, K;
    void Solve() {
        scanf("%d%d", &N, &K);
        vector<int> diff(N + 1);
        for (int i = 0; i < K; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            diff[l] += 1;
            diff[r + 1] -= 1;
        }
        for (int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
        }
        sort(diff.begin(), diff.end());
        printf("%d\n", diff[N / 2]);
    }
};

int main() {
    Solution().Solve();
    return 0;
}