#include <cstdio>
#include <vector>
using namespace std;

typedef long long int64;

struct Solution {
    int N, Q;
    vector<int64> A;

    void Solve() {
        scanf("%d%d", &N, &Q);  
        A.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            scanf("%lld", &A[i]);
        }
        for (int i = 1; i < A.size(); i++) {
            A[i] += A[i - 1];
        }
        for (int i = 0; i < Q; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", A[r] - A[l]);
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
} 