#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    double B; // 必须是double
    int L, N;
    vector<double> Amount, NextAmount;

    void Solve(int caseNo) {
        scanf("%lf%d%d", &B, &L, &N);
        Amount.emplace_back(B * 750.0);// 当前层每个的酒量
        for (int i = 1; i <= L; ++i) {
            NextAmount.clear();
            NextAmount.resize(Amount.size() + i + 1); // 下一层的杯子数等于这一层 + level数 + 1
            int no = 0; // 当前第几号杯子
            for (int j = 1; j <= i; ++j) { // j行 第i层共有i行
                for (int k = 0; k < j; ++k) { // 第k个 第j行有j个
                    double left = min(Amount[no], 250.0); // 多创新变量，能盛的量 = min(酒量， 容量)
                    double extra = Amount[no] - left; // 额外量 = 酒量 - 能盛的量
                    double each = extra / 3.0; 
                    NextAmount[no] += each;
                    NextAmount[no + j] += each; // 下一层与这一层编号关系中关乎于行量，故把for拆成两个
                    NextAmount[no + j + 1] += each;
                    Amount[no++] = left;
                }
            }
            swap(Amount, NextAmount);
        }
        // NextAmount = Amount = 第 i level
        printf("Case #%d: %.9lf\n", caseNo, NextAmount[N - 1]);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}