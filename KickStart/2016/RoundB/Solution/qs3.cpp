#include <algorithm>
#include <cstdio>
#include <limits>
#include <vector>
using namespace std;

typedef long long int64;

struct Segment {
    int L, R;
};

struct Solution {
    int N, X1, Y1, A, B, C1, C2, M;
    vector<Segment> S;
    vector<int> V, W, T1, T2;

    void Solve(int caseNo) {
        scanf("%d%d%d%d%d%d%d%d", &N, &X1, &Y1, &A, &B, &C1, &C2, &M);
        S.resize(N);
        for (int i = 0; i < N; ++i) {
            S[i].L = min(X1, Y1);
            S[i].R = max(X1, Y1);
            V.emplace_back(S[i].L);
            V.emplace_back(S[i].R + 1);
            int newX = ((int64)A * X1 + (int64)B * Y1 + C1) % M;
            int newY = ((int64)A * Y1 + (int64)B * X1 + C2) % M;
            X1 = newX;
            Y1 = newY;
        }
        sort(V.begin(), V.end());
        // unique 去掉 重复元素
        // 返回最后一个的iterator
        V.resize(unique(V.begin(), V.end()) - V.begin());
        W.resize(V.size());
        /*
        L  R
        10  30
        30  40
        20  30

        V: 10 31 30 41 20 31
        V: 10 20 30 31 41
        
        L  R
        0  3
        2  4
        1  3
        
        W: 1 1 1 -2 -1

        */
        for (int i = 0; i < N; ++i) {
            S[i].L =
                lower_bound(V.begin(), V.end(), S[i].L) - V.begin();
            S[i].R =
                lower_bound(V.begin(), V.end(), S[i].R + 1) - V.begin();
            ++W[S[i].L];
            --W[S[i].R];
        }
        // 从0开始到该点一层覆盖的个数
        T1.resize(V.size() + 1);
        // 从0开始到该点多层覆盖的个数
        T2.resize(V.size() + 1);
        int balance = 0, lastV = 0;
        for (int i = 0; i < W.size(); ++i) {
            T1[i + 1] = T1[i];
            T2[i + 1] = T2[i];
            switch (balance) {
                case 0:
                    break;
                case 1:
                    T1[i + 1] += V[i] - lastV;
                    break;
                default:
                    T2[i + 1] += V[i] - lastV;
                    break;
            }
            balance += W[i];
            lastV = V[i];
        }
        int answer = numeric_limits<int>::max();
        for (int i = 0; i < N; ++i) {
            int a0 = T1.back() + T2.back(); // 多层不包括单层
            int a1 = T1[S[i].R + 1] - T1[S[i].L + 1]; // 这条线上单层覆盖点的个数
            int a = a0 - a1; // 这线段拆了之后能覆盖的
            if (a < answer) answer = a; 
        }
        printf("Case #%d: %d\n", caseNo, answer);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}