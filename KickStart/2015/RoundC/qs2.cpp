#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Solution {
    int N;
    vector<double> small, large;
    void Solve(int caseNo) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            double l;
            int r;
            scanf("%lf%d", &l, &r);
            if (r == 0) continue;
            small.emplace_back(r / ((l + 0.999) / 100.0));
            if (l == 0) continue;
            large.emplace_back(r / (l / 100.0));
        }
        double ms = ceil(*max_element(small.begin(), small.end()));
        double ml = floor(*min_element(large.begin(), large.end()));
        printf("Case #%d: %d\n", caseNo, (ms != ml) ? -1 : int(ml));
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 