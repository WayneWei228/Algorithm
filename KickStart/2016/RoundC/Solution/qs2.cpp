#include <cstdio>
#include <vector>
using namespace std;

typedef long long int64;

struct Solution {
    int R, C, K, X, Y;
    vector<vector<int>> A;

    void Solve(int caseNo) {
        scanf("%d%d%d", &R, &C, &K);
        // A[i][j]: 以i, j 为右下角的正方形个数
        A.resize(R);
        for (auto& i : A) i.resize(C, 1);
        for (int i = 0; i < K; ++i) {
            scanf("%d%d", &X, &Y);
            A[X][Y] = 0;
        }
        int64 answer = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (A[i][j] == 0) continue;
                if (i != 0 && j != 0) {
                    int a0 = A[i - 1][j - 1];
                    int a1 = A[i - 1][j];
                    int a2 = A[i][j - 1];
                    A[i][j] = min(min(a0, a1), a2) + 1;
                }
                answer += A[i][j];
            }
        }
        printf("Case #%d: %lld\n", caseNo, answer);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}