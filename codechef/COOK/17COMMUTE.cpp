#include <cstdio>
using namespace std;

typedef long long int64;

struct  Solution {
    int N;
    void Solve() {
        scanf("%d", &N);
        int64 ans = 0;
        for (int i = 0; i < N; i++) {
            int x, l, f;
            scanf("%d%d%d", &x, &l, &f);
            ans = (ans < x) ? x + l: x + (ans - x + f - 1) / f * f + l;         
        }
        printf("%lld\n", ans);
    }
};


int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}