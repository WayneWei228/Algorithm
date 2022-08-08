#include <cmath>
#include <cstdio>
using namespace std;

typedef long long int64;

struct Solution {
    int64 N;

    void Solve(int caseNo) {
        scanf("%lld", &N);
        printf("Case #%d: %lld\n", caseNo, Compute());
    }

    int64 Compute() {
        // 2^64 > 10^18
        for (int i = 64; i >= 2; --i) { // b的最高次的次数
            int64 b = pow(N, 1.0 / i); // b 是几进制
            if (AllOne(b)) return b;
        }
        return N - 1; // N-1 的进制下，两个1
    }

    bool AllOne(int64 b) {
        int64 x = N;
        while (x != 0) {
            if (x % b != 1) return false;
            x /= b;
        }
        return true;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}