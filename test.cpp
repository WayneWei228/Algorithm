#include <cstdio>
#include <vector>

using namespace std;

typedef long long int64;

struct Solution {
    int N;
    int64 ans = 0;
    vector<vector<int>> before;
    char visited[1e5 + 5];
    int f[1e5 + 5];
    int v[1e5 + 5];

    int MinValueCir(int start) {
        int a = start, b = start;
        do {
            a = f(a);
            b = f(f(b));
        } while (a != b);
        
    }

    void Solve() {
        scanf("%d", &N);
        before.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            scanf("%d%d", &f[i], &v[i]);
            ans += v[i];
            before[f[i]].emplace_back(i);
        }
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                ans -= MinValueCir(i);
            }
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
} 