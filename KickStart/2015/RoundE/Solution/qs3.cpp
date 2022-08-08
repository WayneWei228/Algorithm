#include <cstdio>
#include <unordered_map>
using namespace std;

struct Solution {
    int N, X, K, A, B, C;
    unordered_map<int, double> U;

    void Solve(int caseNo) {
        scanf("%d%d%d%d%d%d", &N, &X, &K, &A, &B, &C);
        U.emplace(X, 1.0);
        for (int i = 0; i < N; ++i) {
            unordered_map<int, double> newU;
            for (const auto& j : U) {
                newU[j.first & K] += j.second * 0.01 * A;
                newU[j.first | K] += j.second * 0.01 * B;
                newU[j.first ^ K] += j.second * 0.01 * C;
            }
            swap(U, newU);
        }
        double answer = 0.0;
        for (const auto& i : U) answer += i.first * i.second;
        printf("Case #%d: %.10lf\n", caseNo, answer);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}