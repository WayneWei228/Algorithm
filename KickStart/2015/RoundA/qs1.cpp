#include <cstdio>
#include <cmath>
using namespace std;

typedef long long int64;

// log2(10^18) = 60
// double 2^53, int64 2^64
// middle 2, 4, 8, 16
// symmetric

struct Solution {
    int64 K;
    int time = 0;
    void Solve(int caseNo) {
        scanf("%lld", &K);
        while (true) {
            int c = ilogb(K);
            if (K == (1LL << c)) { // usigned long long ULL
                break;
            }
            K = (1LL << c) * 2 - K ;
            time++;
        }
        printf("Case #%d: %d\n", caseNo, time % 2);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 