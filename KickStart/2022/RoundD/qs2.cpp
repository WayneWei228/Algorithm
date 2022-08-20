#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N, M, K;
    vector<int> A, B;
    vector<vector<vector<vector<int>>>> dp;

    void Solve(int caseNo) {
        scanf("%d", &N);
        A.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
        }
        scanf("%d", &M);
        B.resize(M + 1);
        for (int i = 1; i <= M; i++) {
            scanf("%d", &B[i]);
        }
        scanf("%d", &K);
    
    }
// 1 2 3 4
// 0 1 2 3
    int Compute(int Ai, int Aj, int Bi, int Bj, int k) {
        if ((Ai - 1 + N - Aj) > N || (Bi - 1 + M - Bj) > M) {
            return -999;
        }
        if (k == 0) return 0;

    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}