#include <algorithm>
#include <cstdio>
#include <set>
#include <unordered_set>
#include <vector>
#include <unordered_map>
using namespace std;

struct Solution {
    int N, L1, R1, A, B, C1, C2, M;
    vector<int> X, Y;
    set<pair<int, int>> s;
    unordered_map<int, int> visited;

    void Solve(int caseNo) {
        scanf("%d%d%d%d%d%d%d%d", &N, &L1, &R1, &A, &B, &C1, &C2, &M);
        X.resize(N + 1);
        Y.resize(N + 1);
        X[1] = L1;
        Y[1] = R1;
        s.emplace(L1, R1);
        for (int i = 2; i <= N; i++) {
            Y[i] = (A * Y[i - 1] + B * X[i - 1] + C2) % M;
            X[i] = (A * X[i - 1] + B * Y[i - 1] + C1) % M;
            s.emplace(min(X[i], Y[i]), max(X[i], Y[i]));
        }
        for (auto i : s) {
            for (auto j = i.first; j <= i.second; j++) {
                visited[j]++;
            }
        }
        int total = visited.size();
        int fans = 0;
        for (auto i : s) {
            int ans = 0;
            for (auto j = i.first; j <= i.second; j++) {
                if (visited[j] == 1) ans++;
            }
            fans = max(fans, ans);
        }
        printf("Case #%d: %d\n", caseNo, total - fans);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}