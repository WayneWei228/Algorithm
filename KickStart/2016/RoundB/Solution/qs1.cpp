#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long int64;

struct Solution {
    int L, R;

    void Solve(int caseNo) {
        scanf("%d%d", &L, &R);
        int m = min(L, R);
        printf("Case #%d: %lld\n", caseNo, (int64)m * (m + 1) / 2);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}