#include <cstdio>
using namespace std;

struct Solution {
    int N, D;
    int ans = 0;

    void Solve(int caseNo) {
        scanf("%d%d", &N, &D);
        for (int i = D; i <= N; i += D) {
            Put(i, 2, N - i);
        }
        printf("Case #%d: %d\n", caseNo, ans);
    }
    void Put(int no, int canAdd, int left) {
        if (left < no && left != 0) return;
        if (left == 0) ans++;
        Put(no, canAdd, left - no);
        if (canAdd >= 1) {
            Put(no + 1, canAdd - 1, left - no - 1);
        }
        if (canAdd == 2) {
            Put(no + 2, canAdd - 2, left - no - 2);
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}
