#include <algorithm>
#include <cstdio>
using namespace std;

struct Solution {
    int L, R;
    int num;
    void Solve(int caseNo) {
        scanf("%d%d", &L, &R);
        num = min(L, R);
        int ans = 0;
        for (int i = 0; i <= num; i++) {
            ans += i;
        }
        printf("Case #%d: %d\n", caseNo, ans);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}