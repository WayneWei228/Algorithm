#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    vector<int> C;
    vector<int> M;
    vector<int> Y;
    vector<int> K;
    int total = 1e6;

    void Solve(int caseNo) {
        C.resize(3);
        M.resize(3);
        Y.resize(3);
        K.resize(3);
        for (int i = 0; i < 3; i++) {
            scanf("%d%d%d%d", &C[i], &M[i], &Y[i], &K[i]);
        }
        int c = *min_element(C.begin(), C.end());
        int m = *min_element(M.begin(), M.end());
        int y = *min_element(Y.begin(), Y.end());
        int k = *min_element(K.begin(), K.end());
        printf("Case #%d:", caseNo);
        if (c + m + y + k < total) {
            printf(" IMPOSSIBLE\n");
        } else {
            printf(" %d", c);
            total -= c;
            if (m >= total) {
                printf(" %d", total);
                total = 0;
            } else {
                total -= m;
                printf(" %d", m);
            }
            if (y >= total) {
                printf(" %d", total);
                total = 0;
            } else {
                total -= y;
                printf(" %d", y);
            }
            if (k >= total) {
                printf(" %d\n", total);
                total = 0;
            } else {
                total -= k;
                printf(" %d\n", k);
            }
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}