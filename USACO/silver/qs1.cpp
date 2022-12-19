#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef long long int64;

struct Solution {
    int N;
    vector<int64> height;
    long long total = 0;
    long long avg;
    vector<vector<int>> e;
    vector<int> d;
    vector<vector<pair<int, int64>>> give;
    int ans;

    void DFS(int now, int father) {
        for (auto& next : e[now]) {
            if (next != father) {
                DFS(next, now);
                if (height[next] - avg > 0) {
                    give[next].push_back({now, height[next] - avg});
                    d[now]++;
                } else if (height[next] - avg < 0) {
                    give[now].push_back({next, avg - height[next]});
                    d[next]++;
                } else {
                    ans--;
                }
                height[now] += height[next] - avg;
            }
        }
    }

    void Solve() {
        scanf("%d", &N);
        height.resize(N + 5);
        d.resize(N + 5);
        give.resize(N + 5);
        for (int i = 1; i <= N; i++) {
            scanf("%lld", &height[i]);
            total += height[i];
        }
        avg = total / N;
        e.resize(N + 5);
        for (int i = 0; i < N - 1; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            e[x].emplace_back(y);
            e[y].emplace_back(x);
        }
        ans = N - 1;
        DFS(1, -1);
        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (d[i] == 0) {
                q.emplace(i);
            }
        }
        printf("%d\n", ans);
        while (q.size()) {
            auto u = q.front();
            q.pop();
            for (auto next : give[u]) {
                printf("%d %d %lld\n", u, next.first, next.second);
                d[next.first]--;
                if (d[next.first] == 0) {
                    q.emplace(next.first);
                }
            }
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}