#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Solution {
    int N;
    vector<int> v;
    void Solve(int caseNo) {
        scanf("%d", &N);
        v.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &v[i]);
        }
        sort(v.begin(), v.end());
        int ans = 1;
        for (auto i : v) {
            if (i >= ans) {
                ans++;
            }
        }
        printf("Case #%d: %d\n", caseNo, ans - 1);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 