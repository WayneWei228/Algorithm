#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Solution {
    void Solve(int caseNo) {
        double a, b;
        scanf("%lf %lf", &a, &b);
        double x = min(9.8 * b / (a * a), 1.0); // 
        x = asin(x) * (90.0 / M_PI);
        printf("Case #%d: %.6f\n", caseNo, x);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}