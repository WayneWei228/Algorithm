#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Solution {
    int N, M;
    double ans = 0.0;
    vector<int> A;
    void Solve() {
        scanf("%d%d", &N, &M);
        A.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        sort(A.begin(), A.end(), [&](int a, int b){
            return a > b;
        });
        int i;
        for (i = 0; i < M - 1; i++) {
            ans += A[i];
        }
        int leftsize = N - i;
        if  (leftsize % 2 == 0) {
            leftsize /= 2;
            ans += double(A[i + leftsize - 1] + A[i + leftsize]) / 2;
        } else {
            ans += A[i + leftsize / 2];
        }
        printf("%.6f\n", ans);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
} 