#include <cstdio>
using namespace std;

struct Solution {
    int N, M;
    int total = 0;
    void Solve(int caseNo) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++) {
            int a;
            scanf("%d", &a);
            total += a;
        }
        int c = total / M;
        printf("Case #%d: %d\n", caseNo, total - c * M);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}