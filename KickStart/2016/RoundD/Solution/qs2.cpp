
#include <cstdio>
using namespace std;

struct Solution {
    int R, C;

    void Solve(int caseNo) {
        scanf("%d%d", &R, &C);
        printf("Case #%d: %d\n", caseNo, Compute());
    }

    int Compute() {
        if (R == 2 || C == 2) return (R * C + 2) / 3 * 2;
        return (R * C * 2 + 2) / 3; // R * C * 2 / 3 的上取整
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}