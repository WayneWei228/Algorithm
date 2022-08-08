#include <cstdio>
using namespace std;


struct Solution {
    int N, M;
    double ans = 0.0;

    void Solve(int caseNo) {
        scanf("%d%d", &N, &M);
        if (M == 0) {
            printf("Case #%d: %.9lf\n", caseNo, 1.000000000);
            return;
        }
        ans += double(M) / (N + M);
        for (int i = 1; i <= M; i++) {
            int total = N + M;
            double temp = 1.0;
            int n = N; 
            int m = M;
            int l = i;
            int r = i;
            while (l > 0) {
                temp *= (double) n / (total);
                n--;
                total--;
                l--;
            }
            while (r > 0) {
                temp *= (double) m / total;
                m--;
                total--;
                r--;
            }
            ans += temp;
        }
        printf("Case #%d: %.9lf\n", caseNo, 1.0 - ans);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 