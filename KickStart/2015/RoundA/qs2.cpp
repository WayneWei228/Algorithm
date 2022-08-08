#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int64;


struct Solution {
    int N, M;
    vector<int64> dimention;
    void Solve(int caseNo) {
        scanf("%d%d", &N, &M);
        dimention.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%lld", &dimention[i]);
        }
        printf("Case #%d:\n", caseNo);
        for (int i = 0; i < M; i++) {
            double ans = 1.0;
            int l, r;
            scanf("%d%d", &l, &r);
            double size = r - l + 1;
            for (int k = l; k <= r; k++) {
                ans *= pow(dimention[k], 1.0 / size);
            }
            printf("%.9lf\n", ans);
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}