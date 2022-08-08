#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N, K;
    vector<int> v[4];
    void Solve(int caseNo) {
        scanf("%d%d", &N, &K);

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < N; j++) {
                int d;
                scanf("%d", &d);
                v[i].emplace_back(d);
            }
        }
        int ans = 0;
        for (auto i : v[0]) {
            for (auto j : v[1]) {
                for (auto k : v[2]) {
                    for (auto z : v[3]) {
                        if ((i ^ j ^ k ^ z) == K) {
                            ans++;
                        }
                    }
                }
            }
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