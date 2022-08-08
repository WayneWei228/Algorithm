#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

struct Solution {
    int N, X, K;
    double A, B, C;
    vector<unordered_map<int, double>> v;

    void Solve(int caseNo) {
        int a, b, c;
        scanf("%d%d%d%d%d%d", &N, &X, &K, &a, &b, &c);
        A = double(a / 100.0);
        B = double(b / 100.0);
        C = double(c / 100.0);
        v.resize(N + 1);
        v[0].emplace(X, 1.00);
        for (int i = 0; i < N; i++) {
            for (auto p : v[i]) {
                int newa = (p.first & K);
                double newPa = p.second * A;
                v[i + 1][newa] += newPa;
                int newb = (p.first | K);
                double newPb = p.second * B;
                v[i + 1][newb] += newPb;
                int newc = (p.first ^ K);
                double newPc = p.second * C;
                v[i + 1][newc] += newPc;
            }
        }
        double ans = 0;
        for (auto i : v[N]) {
            ans += i.first * i.second;
        }
        printf("Case #%d: %.10lf\n", caseNo, ans);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 