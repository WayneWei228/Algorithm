#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int P, E, T, M;
    vector<double> p, e, t;
    void Solve(int caseNo) {
        scanf("%d%d%d", &P, &E, &T);
        p.resize(P);
        e.resize(E);
        t.resize(T);
        for (int i = 0; i < P; i++) {
            scanf("%lf", &p[i]);
        }
        for (int i = 0; i < E; i++) {
            scanf("%lf", &e[i]);
        }
        for (int i = 0; i < T; i++) {
            scanf("%lf", &t[i]);
        }
        scanf("%d", &M);
        printf("Case #%d:\n", caseNo);
        for (int i = 0; i < M; i++) {
            double a, b;
            scanf("%lf%lf", &a, &b);
            double ans = a / b;
            bool flag = false;
            for (int x1 = 0; x1 < p.size(); x1++) {
                for (int x2 = 0; x2 < e.size(); x2++) {
                    for (int x3 = x2 + 1; x3 < e.size(); x3++) {
                        for (int x4 = 0; x4 < t.size(); x4++) {
                            if (p[x1] / e[x2] * e[x3] / t[x4] == ans) {
                                flag = true;
                            }
                        }
                    }
                }
            }
            printf("%s\n", (flag) ? "Yes" : "No");
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 