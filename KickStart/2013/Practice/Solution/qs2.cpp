#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Solution {
    void Solve(int caseNo) {
        double v, d;
        scanf("%lf%lf", &v, &d);
        // 浮点有误差，会算成 1.000000000001，所以 asin(x) 不工作 (if x > 1.0)
        // 所以拿 1.0 限制 x
        double x = min(9.8 * d / (v * v), 1.0);
        printf("Case #%d: %.6f\n", caseNo, asin(x) * (90.0 / M_PI));
    } 
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}