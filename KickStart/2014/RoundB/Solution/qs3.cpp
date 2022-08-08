#include <cstdio>
#include <limits>
#include <vector>
using namespace std;

struct Solution {
    int N, K;
    
    // 中间可能的状态数太多

    vector<int> A; // 给定的数
    vector<vector<int>> F; // F[i][j]：A 从i开始拿j个数，单独拿出来，如果按照题目规则，最少剩几个
    // 一个区间，消除区间过程中，存不存在其中一次同时消除区间最左边和最右边的数
    // 如果存在，一定是最后一次
    // 枚举各种情况
    // 2 L 5 R 8 满足 L 和 R 消没了 -> 进入情况 1
    // 情况 1 左右同时被消
    // 2 L 5 R 8
    // L, R 消没了
    // 所以整个答案都是 0 
    // 情况 2 左右均被消，但不同时
    // 2 L 3 L 4 | ... 6 Q 7 P 8
    // 分两段 ans = ansL + ansR
    // 枚举砍断的位置，取最好结果
    // 情况3 左边或者右边没被消
    // 3.1 左边没被消
    // F[i + 1][j - 1] + 1
    // 3.2 右边没被消
    // F[i][j - 1] + 1
    // 四种情况取最小

    void Solve(int caseNo) {
        scanf("%d%d", &N, &K);
        A.resize(N);
        for (int& i : A) scanf("%d", &i);
        F.resize(N + 1);
        // F[N][0] = 0;
        for (int i = N; i >= 0; --i) {
            F[i].resize(N + 1 - i);
            for (int j = 1; j < F[i].size(); ++j) { // 算 F[i][j]
                int m0 = F[i][j - 1] + 1; // 3.2
                int m1 = F[i + 1][j - 1] + 1; // 3.1
                if (m1 < m0) m0 = m1; // 取小
                for (int k = 1; k < j - 1; ++k) { // 情况 1 line 18 枚举 5 的位置
                    if (A[i] + K != A[i + k]) continue; // 不能消
                    if (A[i + k] + K != A[i + j - 1]) continue; // 不等于最后一个数
                    if (F[i + 1][k - 1] != 0) continue; // L 消不掉
                    // j - 3 - (k - 1)
                    if (F[i + k + 1][j - 2 - k] != 0) continue; // R 消不掉
                    m0 = 0;
                }
                for (int k = 1; k < j; ++k) { // 情况 2
                    int m2 = F[i][k] + F[i + k][j - k];
                    if (m2 < m0) m0 = m2;
                }
                F[i][j] = m0; // 赋值
            }
        }
        printf("Case #%d: %d\n", caseNo, F[0][N]);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}