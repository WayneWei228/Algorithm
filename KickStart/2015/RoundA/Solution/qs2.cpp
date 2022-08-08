#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;


/*
2 * 2 * 4 * 8
1 + 1 + 2 + 3 = 7
2 ^ 7 = ans


pi ^ pi
log 和 exp 都均可对所有实数取
log pi  * pi
exp(pi * log pi) (以e为底) e的pi * logpi次方 = pi ^ pi

pi ^ 2pi
exp(log(pi) * 2pi)

a^b * c^d
exp(log(a)*b + log(c)*d)

前缀乘 = 对每个数取log 再按照前缀和处理
最后exp
*/
struct Solution {
    int N, M;
    vector<double> A, B;

    void Solve(int caseNo) {
        scanf("%d%d", &N, &M);
        A.resize(N);
        for (auto& i : A) {
            double x;
            scanf("%lf", &x);
            i = log(x);
        }
        B.resize(N + 1);
        for (int i = 1; i <= N; ++i) B[i] = B[i - 1] + A[i - 1]; 
        printf("Case #%d:\n", caseNo);
        for (int i = 0; i < M; ++i) {
            int aL, aR;
            scanf("%d%d", &aL, &aR);
            printf("%.9lf\n", exp((B[aR + 1] - B[aL]) / (aR + 1 - aL)));
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}