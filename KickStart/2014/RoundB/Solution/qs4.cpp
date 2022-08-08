#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;

const int M = 100;
vector<vector<int64>> A;
/*
以某个串s为前缀的合法扣号序列的数量 计作 F[s]
123456 第100个 用下标99表示更清晰
F[1] = F[12] + F[13] + F[14] + F[15] + F[16]
1 有 5种岔路
K比F[1]大
看K和F[2]
K比F[21]小
那就在F[21]里
K比F[213]大
看K和F[214]
*/

struct Solution {
    int N;
    int64 K;
    string Answer;

    void Solve(int caseNo) {
        scanf("%d%lld", &N, &K);
        // 题中A[i][j] 表示 （还剩）i个右括号,j个左括号的放法

        if (A[N][N] < K) { // K 大于 所有可能性 卡特兰数
        // A[i][j] 表示 F[i个右括号,j个左括号，任意排列]
        // F[()()] 后面能跟的东西 = F[(())] 后面能跟的东西
        // F[ ()( ] = F[ (() ] 后面的东西都是一个平衡序列+右括号
        // 到某个点之后能接什么东西只跟这个点之前左右括号的数量有关
        // 这就是用A[i][j] 代替 F[s]
        // F[()()] = A[2][2];
            printf("Case #%d: Doesn't Exist!\n", caseNo);
        } else {
            int numL = N, numR = N; // 还剩 numL个左括号 numR个右括号
            for (int i = 0; i < N + N; ++i) {
                // 如果还能放0个左括号或者放左括号之后的可能数 < K 才放右括号
                if (numL == 0 || A[numR][numL - 1] < K) { // 往右走 能剪才能往右
                    K -= A[numR][numL - 1]; // K - 往左走的那么些路
                    // 把放 '(' 的步骤都走掉才能走 ')'
                    --numR; // 往右走b
                    Answer += ')';
                } else {
                    --numL;
                    Answer += '(';
                }
            }
            printf("Case #%d: %s\n", caseNo, Answer.c_str());
        }
    }
};

int main() {
    A.resize(M + 1);
    for (int i = 0; i <= M; ++i) {
        A[i].resize(i + 1); // 任何时刻还剩的右括号一定比左括号多
        A[i][0] = 1;
        for (int j = 1; j < A[i].size(); ++j) {
            // j < i + 1
            // j <= i
            // i >= j
            // A[i][j] = A[i - 1][j] + A[i][j - 1]
            // eg. A[3][3] = A[2][3] +  A[3][2]
            // A[i - 1].size() = i
            // 所以只有当 j < i 的时候才能拿A[i - 1][j]，否则为0
            int64 t = A[i][j - 1] + (j < i ? A[i - 1][j] : 0); // int64会爆，
            A[i][j] = min(t, int64(1e18)); // 不影响solve
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}