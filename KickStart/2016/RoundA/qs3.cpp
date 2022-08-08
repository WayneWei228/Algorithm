#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

double BSearch(double lower, double upper, function<bool(double)> f) {
    while (lower < upper) {
        double mid = lower + (upper - lower) * 0.5;
        f(mid) ? upper = mid : lower = mid + 1e-9;
    }
    return lower;
}

struct Solution {
    int M;
    vector<double> cost;

    void Solve(int caseNo) {
        scanf("%d", &M);
        for (int i = 0; i <= M; i++) {
            double d;
            scanf("%lf", &d);
            cost.emplace_back(d);
        }
        double answer = BSearch(-1.0, 1.0, [this](double r) {
            return Calculate(r);
        });
        printf("Case #%d: %.9lf\n", caseNo, answer);
    }

    bool Calculate(double r) {
        int m = M;
        double ans = -cost[0] * pow((1.0 + r), m--);
        for (int i = 1; i <= M; i++) {
            ans += cost[i] * pow((1.0 + r), m--);
        }
        return ans < 0;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}