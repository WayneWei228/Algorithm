#include <algorithm>
#include <cstdio>
#include <vector>
#include <limits>
#include <functional>
using namespace std;

int BSearch(int lower, int upper, function<bool(int)> f) {
    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        f(mid) ? upper = mid : lower = mid + 1;
    }
    return lower;
}

struct Solution {
    int N, M, C1, C2, Gap = 0, Answer;
    int Bound1, Bound2;
    vector<int> C;

    void Solve() {
        scanf("%d%d%d%d", &N, &M, &C1, &C2);
        if (C2 < C1) swap(C1, C2);
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            C.emplace_back(x);
        }
        C.emplace_back(C1);
        C.emplace_back(C2);
        N += 2;
        sort(C.begin(), C.end());
        Bound1 = lower_bound(C.begin(), C.end(), C1) - C.begin();
        Bound2 = lower_bound(C.begin(), C.end(), C2) - C.begin();
        for (int i = Bound1 + 1; i <= Bound2; i++) {
            int gap = C[i] - C[i - 1];
            if (gap > Gap) Gap = gap;
        }
        printf("%d\n", Compute());
    }

    int Compute() {
        if (Bound2 - Bound1 - 1 >= M) {
            return BSearch(Gap, C2 - C1, [&](int gap) {
                int current = C[Bound1];
                int ans = 0;
                for (int i = Bound1 + 1; i < Bound2; i++) {
                    if (C[i + 1] - current <= gap) continue;
                    current = C[i];
                    ++ans;
                }
                return ans <= M;
            });
        }
        int num = Bound2++ - (Bound1 + 1);
        int inf = numeric_limits<int>::max();
        int ans = Gap;
        while (num < M) {
            int g1 = 0 < Bound1 ? C[Bound1] - C[Bound1 - 1] : inf;
            int g2 = Bound2 < N ? C[Bound2] - C[Bound2 - 1] : inf;
            if (g1 < g2) {
                Bound1--;
                if (ans < g1) ans = g1;
            } else {
                Bound2++;
                if (ans < g2) ans = g2;
            }
            num++;
        }
        return ans;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}