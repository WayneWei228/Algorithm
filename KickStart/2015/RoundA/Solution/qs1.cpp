#include <cmath>
#include <cstdio>
#include <limits>
using namespace std;

typedef long long int64;

struct Solution {
    int64 N;

    void Solve(int caseNo) {
        scanf("%lld", &N);
        printf("Case #%d: %d\n", caseNo,
               Get(N - 1, numeric_limits<int64>::max())); 
        // 从0开始的话 对称轴 0 1 3 7... = 2^N - 1
    }

    int Get(int64 index, int64 m) { // m : 对称轴
        if (index < m) return Get(index, m / 2);
        if (index == m) return 0;
        return 1 - Get(m + m - index, m / 2); // 在对称轴 右边，转换算对称轴左边
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}