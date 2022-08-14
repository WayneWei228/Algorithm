#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N;
    vector<int> A;

    int GCD (int a, int b) {
        if (b == 0) return a;
        else return GCD(b, a % b);
    }

    void Solve() {
        scanf("%d", &N);
        A.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        int divisor = 0;
        for (int i = 0; i < N; i++) {
            divisor = GCD(A[i], divisor);
        }
        bool head = true;
        for (int i = 0; i < N; i++) {
            if (!head) printf(" ");
            head = false;
            printf("%d", A[i] / divisor);
        }
        printf("\n");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
} 