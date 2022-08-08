#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int64;

/*
x0 * x1 * Q = y1 * y2 * P (x1 != y1)

x0 / x1 * y1 / y2 = P / Q
x0 * y1 * Q =  x1 * y2 * P

*/

struct Solution {
    int N0, N1, N2, M, P, Q;
    vector<int> V0, V1, V2;

    void Solve(int caseNo) {
        scanf("%d%d%d", &N0, &N1, &N2);
        V0.resize(N0);
        for (int i = 0; i < N0; ++i) scanf("%d", &V0[i]);
        V1.resize(N1);
        for (int i = 0; i < N1; ++i) scanf("%d", &V1[i]);
        V2.resize(N2);
        for (int i = 0; i < N2; ++i) scanf("%d", &V2[i]);
        printf("Case #%d:\n", caseNo);
        scanf("%d", &M);
        for (int i = 0; i < M; ++i) {
            scanf("%d%d", &P, &Q);
            printf(OK() ? "Yes\n" : "No\n");
        }
    }

    bool OK() {
        unordered_map<int64, int> count;
        for (int64 i : V1) {
            for (int64 j : V0) ++count[i * j * Q];
        }
        for (int64 i : V1) {
            for (int64 j : V0) --count[i * j * Q]; // 44 要用，所以42去掉
            for (int64 j : V2) {
                if (count[i * j * P]) return true;
            }
            for (int64 j : V0) ++count[i * j * Q];
        }
        return false;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}