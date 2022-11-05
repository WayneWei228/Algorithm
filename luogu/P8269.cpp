#include <algorithm>
#include <cstdio>
#include <limits>
#include <vector>

using namespace std;

typedef long long int64;

struct Solution {
    int N;
    int64 ans = 0;
    vector<vector<int>> before;
    char visited[100005];
    int f[100005];
    int v[100005];

    void Mark(int x) {
        if (visited[x]) return;
        visited[x] = true;
        for (auto i : before[x]) {
            Mark(i);
        }
        return;
    }

    int MinValueCir(int start) {
        int a = start, b = start;
        do {
            a = f[a];
            b = f[f[b]];
        } while (a != b);

        int Min = numeric_limits<int>::max();
        do {
            Min = min(Min, v[a]);
            a = f[a];
        } while (a != b);
        Mark(a);
        return Min;
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
        printf("%lld\n", ans);
    }
};

int main() {
    Solution().Solve();
    return 0;
}