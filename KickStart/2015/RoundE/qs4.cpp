#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int64;

struct Solution {
    int N, Q;
    vector<int64> po;
    vector<int64> pf;

    void Solve(int caseNo) {
        scanf("%d%d", &N, &Q);
        po.emplace_back(0);
        for (int i = 0; i < N; i++) {
            int d;
            scanf("%d", &d);
            po.emplace_back(d);
        }
        for (int i = 1; i < po.size(); i++) {
            po[i] += po[i - 1];
        }
        for (int i = 1; i < po.size(); i++) {
            for (int j = i; j < po.size(); j++) {
                pf.emplace_back(po[j] - po[i - 1]);
            }
        }
        sort(pf.begin(), pf.end());
        pf.insert(pf.begin(), 0);
        for (int i = 1; i < pf.size(); i++) {
            pf[i] += pf[i - 1];
        }
        po.clear();
        printf("Case #%d:\n", caseNo);
        for (int i = 0; i < Q; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", pf[r] - pf[l - 1]);
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}