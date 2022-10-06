#include <cstdio>
#include <vector>
using namespace std;

typedef long long int64;

struct Solution {
    int N;
    int64 ans = 0;

    void Solve() {
        scanf("%d", &N);
        vector<int64> arr(N + 1);
        arr[0] = 0;
        vector<int64> nums(N, -1);
        nums[0] = 0;
        for (int i = 1; i <= N; i++) {
            scanf("%lld", &arr[i]);
            arr[i] += arr[i - 1];
            arr[i] %= N;
            arr[i] = (arr[i] + N) % N;
            ans += ++nums[arr[i]];
        }
        printf("%lld\n", ans);
    }
};

int main() {
    Solution().Solve();
    return 0;
}