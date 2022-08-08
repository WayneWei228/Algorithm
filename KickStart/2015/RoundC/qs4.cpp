#include <algorithm>
#include <cstdio>
#include <limits>
#include <vector>
using namespace std;

typedef long long int64;

struct Solution {
    int N, K, C;
    int64 X;
    vector<vector<int>> matrix;
    vector<int> A, B;
    int64 ans = 0;

    void Solve(int caseNo) {
        scanf("%d%d%d%lld", &N, &K, &C, &X);
        matrix.resize(N + 1);
        for (auto& i : matrix) i.resize(N + 1);
        A.resize(N + 1);
        B.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 1; i <= N; i++) {
            scanf("%d", &B[i]);
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                matrix[i][j] = (A[i] * i + B[j] * j + C) % X;
            }
        }
        for (int i = 1; i + K - 1 <= N; i++) {
            for (int j = 1; j + K - 1 <= N; j++) {
                int m = matrix[i][j];
                for (int x = 0; x < K; x++) {
                    for (int y = 0; y < K; y++) {
                        if (matrix[i + x][j + y] > m) {
                            m = matrix[i + x][j + y];
                        }
                    }
                }
                ans += m;
            }
        }
        printf("Case #%d: %lld\n", caseNo, ans);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}