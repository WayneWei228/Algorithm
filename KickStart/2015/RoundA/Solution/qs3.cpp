#include <algorithm>
#include <cstdio>
#include <limits>
#include <vector>
using namespace std;
/*
Floyd–Warshall algorithm
给一个图求两两最短路

A[i][j]: i to j 的 最短路 但中间只能走 1 ... K 的点
K 从 1 遍 N
K = N
A[i][j] = answer;

最开始开通k
计算A[i][k] + A[k][j]
与 A[i][j] 比较
更新

依次开通 K (1 ... N)
for (k) {
    for (i) {
        for (j) {
            if (A[i][j] > A[i][k] + A[k][j]) {
                A[i][j] = A[i][k] + A[k][j]
            }
        }
    }
}

*/

struct Edge {
    int U, V, C; // 从哪到哪长度多少
};

struct Solution {
    int N, M;
    vector<Edge> E; // 所有的边 按输入顺序
    vector<vector<int>> A;

    void Solve(int caseNo) {
        scanf("%d%d", &N, &M);
        E.resize(M);
        A.resize(N);
        for (auto& i : A) i.resize(N, numeric_limits<int>::max() / 2);
        for (int i = 0; i < M; ++i) {
            // 邻接矩阵 永远取最短的
            scanf("%d%d%d", &E[i].U, &E[i].V, &E[i].C);
            A[E[i].U][E[i].V] = min(A[E[i].U][E[i].V], E[i].C);
            A[E[i].V][E[i].U] = min(A[E[i].V][E[i].U], E[i].C);
        }
        for (int i = 0; i < N; ++i) A[i][i] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    A[j][k] = min(A[j][k], A[j][i] + A[i][k]);
                }
            }
        }
        printf("Case #%d:\n", caseNo);
        for (int i = 0; i < M; ++i) {
            if (A[E[i].U][E[i].V] < E[i].C) printf("%d\n", i); 
            // 两最短距离小于这两点直连边
            // 直连边则无用
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}