#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N, P;
    vector<int> ans;
    bool head = true;
    void Solve(int caseNo) {
        scanf("%d", &N);
        ans.resize(5005);
        for (int i = 0; i < N; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            ans[l]++;
            ans[r + 1]--;
        }
        for (int i = 1; i < 5005; i++) {
            ans[i] += ans[i - 1];
        }
        printf("Case #%d:", caseNo);
        scanf("%d", &P);
        for (int i = 0; i < P; i++) {
            int c;
            scanf("%d", &c);
            printf(" %d", ans[c]);
        }
        printf("\n");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}