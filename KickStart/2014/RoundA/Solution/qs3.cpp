#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

// 从lower到upper之间找第一个f为真的，用户需保证f(upper)为真
// 返回值可能是 lower 到 upper 之间的任意一个数，两边包含
// 如果要查询lower 到 upper 之间最后一个f为假，调用此函数结果-1即可
// f 从前往后 先假后真 
// 有序性要求
// 前面一段不符合条件，突然有一点满足调节及之后全部满足
// 此函数不会询问 f(upper) 强行假设f(upper)为真
// 可找到数组中第一个大于等于目标值的位置 similar to lowerbound
// upperbound 同理

int BSearch(int lower, int upper, function<bool(int)> f) {
    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        f(mid) ? upper = mid : lower = mid + 1;
    }
    return lower;
}

typedef long long int64;

struct Solution {
    int N, M;
    vector<int64> BreakM, Need;

    void Solve(int caseNo) {
        scanf("%d%d", &N, &M);
        Cut(M, M, BreakM);
        Need.resize(BreakM.size());
        for (int i = 0; i < N; ++i) {
            scanf("%d", &M);
            ++Need[M];
        }
        int no = BSearch(1, N, [this](int64 no) {
            int64 left = 0;
            for (int i = BreakM.size() - 1; i >= 0; --i) {
                // 一层一层下来 8 7 6 5，不会跳过
                // 上一轮留下来的现在变4倍
                // 一个 M * M 能割出多少个2的i次方
                // no个 M * M 能割出多少个2的i次方
                // 正常情况下能割下 2 的 i 次方数量 + 上轮没用留下来的
                // 如果比 N 还大，没用
                left = min(int64(N), left * 4 + BreakM[i] * no);
                if (left < Need[i]) return false;
                left -= Need[i];
            }
            return true;
        });
        printf("Case #%d: %d\n", caseNo, no);
    }

    // n 短 m 长
    void Cut(int n, int m, vector<int64>& into) {
        // n * m 的一个块
        // 切割成2的若干次方形式，能切大尽量切大，然后放进into
        // into[0] 为 2 ^ 0 有几块
        int b = ilogb(n);  // log2下取正 这个数大约是2的多少次方
        int64 s = m >> b;  // m 这条边能放多少个 2 ^ b
        // n 只能容纳一个2的b次
        // >> b
        // = 除以 2的b次
        if (into.size() <= b) into.resize(b + 1);
        into[b] += s; 
        int64 mL = m & ((1 << b) - 1); // m还剩的长度
        // 模2的b次就等于 且2的b次-1 
        // % 2 = & 1
        // % 4 = & 3
        // % 8 = & 7
        // % n = & n - 1 if n 为 2的次方
        int64 nL = n & ((1 << b) - 1); // n还剩的
        assert(mL == nL); // 要求这ml 和 nl相等，否则RTE（run time error)
        if (nL) Cut(nL, m + (1 << b), into); // L型变I型
        // 跟初始是正方形有联系
        // 思考： L变I可能造成两小块废料结合可拼成一个大的
        // 为什么 ml == nl
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}