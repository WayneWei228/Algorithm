#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Solution {
    int N, M;
    long long answer = 0;
    set<pair<int, int>> store;
    vector<vector<int>> edges;
    vector<int> reversed, visited, father, sz, degree;

    int Find(int x) {
        if (father[x] != x) {
            return father[x] = Find(father[x]);
        } else {
            return father[x] = x;
        }
    }

    void Union(int x, int y) {
        y = Find(y);
        x = Find(x);
        if (x == y) {
            return;
        }
        father[x] = y;
        sz[y] += sz[x];
    }

    void Solve() {
        scanf("%d%d", &N, &M);

        degree.resize(N + 1);
        edges.resize(N + 1);
        visited.resize(N + 1);
        father.resize(N + 1);
        sz.resize(N + 1);

        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            edges[u].emplace_back(v);
            edges[v].emplace_back(u);
            degree[u]++;
            degree[v]++;
        }

        int total;
        for (int i = 1; i <= N; i++) {
            if (degree[i] > 0) {
                total++;
            }
        }

        for (int i = 1; i <= N; i++) {
            father[i] = i;
            sz[i] = 1;
            store.emplace(make_pair(degree[i], i));
        }

        while (store.size()) {
            auto now = store.begin();
            int u = now->second;
            store.erase(now);
            visited[u] = 1;
            reversed.emplace_back(u);
            for (int i : edges[u]) {
                if (visited[i] == 0) {
                    store.erase(make_pair(degree[i], i));
                    degree[i]--;
                    store.insert(make_pair(degree[i], i));
                }
            }
        }

        vector<int> z;
        z.resize(N + 1);

        for (int i = reversed.size() - 1; i >= 0; i--) {
            z[reversed[i]] = 1;
            long long number = 0;
            for (int j : edges[reversed[i]]) {
                if (z[j]) {
                    number++;
                    Union(reversed[i], j);
                }
            }
            answer = max(answer, number * sz[Find(reversed[i])]);
        }
        printf("%lld\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
