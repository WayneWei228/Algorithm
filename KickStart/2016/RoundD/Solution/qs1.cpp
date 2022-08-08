#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N, M;
    vector<vector<double>> A; 
    // 已有a个人投A，b个人投B的情况下，A步步赢的概率

    void Solve(int caseNo) {
        scanf("%d%d", &N, &M);
        A.resize(N + 1);
        for (auto& i : A) i.resize(M + 1);
        A[N][M] = 1.0;
        for (int i = N; i >= 0; --i) {
            for (int j = M; j >= 0; --j) {
                if (i <= j) continue;
                int x0 = N - i, x1 = M - j;
                if (x0 + x1 == 0) continue; // A[N][M]
                if (x0) A[i][j] += x0 * A[i + 1][j];
                if (x1) A[i][j] += x1 * A[i][j + 1];
                A[i][j] /= x0 + x1;
            }
        }
        // N / (N + M) 第一个人投A的概率
        // A[1][0] 在第一个人投A之后保证步步赢的概率
        printf("Case #%d: %.7lf\n", caseNo, A[1][0] * N / (N + M)); 
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}