#include <algorithm>
#include <cstdio>
#include <iostream>
#include <limits>
using namespace std;

typedef long long int64;

struct Solution {
    int64 cow1, cow2;
    void Solve() {
        cin >> cow1 >> cow2;
        int64 ans = numeric_limits<int>::max();
        for (int num2 = 0; cow2 >> num2 > 0; num2++) {
            int64 here = num2; // must be int64
            int64 prefix = cow2 >> num2; // must be int64
            int64 cow = cow1;
            while (cow > prefix) {
                if (cow % 2LL == 1LL) {
                    ++cow;
                    ++here;
                }
                cow /= 2LL;
                ++here;
            }
            here += prefix - cow;
            here += __builtin_popcountll(cow2 & ((1LL << num2) - 1LL));
            ans = min(ans, here);
        }
        cout << ans << endl;
    }
};

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        Solution().Solve();
    }
    return 0;
}