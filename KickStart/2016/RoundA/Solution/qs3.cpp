#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

// 实数无限可分，不加1e-9
// 
double BSearch(double lower, double upper, function<bool(double)> f) {
    while (true) {
        double mid = (lower + upper) * 0.5;
        if (upper < lower + 1e-9) return mid;
        f(mid) ? upper = mid : lower = mid;
    }
}

struct Solution {
    int M;
    double Cost;
    vector<double> R;

    void Solve(int caseNo) {
        scanf("%d%lf", &M, &Cost);
        R.resize(M);
        for (double& i : R) scanf("%lf", &i);
        printf("Case #%d: %.7lf\n", caseNo, IRR());
    }

    double IRR() {
        return BSearch(-1.0, 1.0, [this](double r) {
            double answer = -Cost;
            // 多项式计算的horner规则 
            for (double i : R) answer = answer * (1.0 + r) + i;
            return answer < 0;
        });
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}