#include <cstdio>
#include <vector>
using namespace std;

const int M = 5000;

struct Solution {
    int N, P;
    vector<int> D;

    void Solve(int caseNo) {
        scanf("%d", &N);
        D.resize(M + 2);
        for (int i = 0; i < N; ++i) {
            int v0, v1;
            scanf("%d%d", &v0, &v1);
            ++D[v0];
            --D[v1 + 1];
        }
        for (int i = 1; i < D.size(); ++i) D[i] += D[i - 1];
        scanf("%d", &P);
        printf("Case #%d:", caseNo);
        for (int i = 0; i < P; ++i) {
            int v;
            scanf("%d", &v);
            printf(" %d", D[v]);
        }
        printf("\n");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}