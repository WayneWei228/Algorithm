#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

typedef long long int64;

/*
保证至少有一个解
所以没有假数据
因此可证明小于大于不会同时出现

1 2 3 3 4 5 不降序数组
目标：找出所有三
方法：找第一个大于等于三 begin
     找第一个大于三 end
     这之间都是三
     这两个找三过程都可以通过二分实现
*/

int64 BSearch(int64 lower, int64 upper, function<bool(int64)> f) {
    while (lower < upper) {
        int64 mid = lower + (upper - lower) / 2;
        f(mid) ? upper = mid : lower = mid + 1;
    }
    return lower;
}

struct Solution {
    int N;
    int64 P, Fixed = -1;
    vector<int64> K;

    void Solve(int caseNo) {
        scanf("%d", &N);
        K.resize(N);
        int64 sumP = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%lld%lld", &P, &K[i]);
            if (P == 100) Fixed = K[i];
            sumP += P;
        }
        int64 lower =
            BSearch(0, 1e15, [&](int64 n) { return SumP(n) <= sumP; });
        if (Fixed != -1 && lower < Fixed) lower = Fixed;
        int64 upper =
            BSearch(0, 1e15, [&](int64 n) { return SumP(n) < sumP; });
        --upper;
        if (Fixed != -1 && Fixed < upper) upper = Fixed;
        if (lower == upper) {
            printf("Case #%d: %lld\n", caseNo, lower);
        } else {
            printf("Case #%d: -1\n", caseNo);
        }
    }

    int64 SumP(int64 n) {
        int64 answer = 0;
        for (int i = 0; i < N; ++i) {
            answer += K[i] * 100 / n;
        }
        return answer;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}