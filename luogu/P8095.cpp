#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Solution {
    int N, M;
    int food[100500];
    vector<pair<int, int>> W[100500];
    int x[100020];
    int y[100020];
    int v[100020];
    int o[100020];
    vector<int> z;
    queue<int> q;
    int sum = 0;
    void Solve() {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            cin >> x[i] >> y[i];
            food[x[i]]++;
            food[y[i]]++;
            // W[x[i]].emplace_back(make_pair(y[i]));
            W[y[i]].emplace_back(make_pair(x[i], i));
            W[x[i]].emplace_back(make_pair(y[i], i));
        }
        for (int i = 1; i <= M; i++) {
            if (food[i] == 1) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            for (auto next : W[now]) {
                if (v[next.second] == 0) {
                    food[now]--;
                    food[next.first]--;
                    if (food[next.first] == 1) {
                        q.emplace(next.first);
                    }
                    z.push_back(next.first);
                    v[next.second] = 1;
                    sum++;
                }
            }
        }
        for (int i = 1; i <= M; i++) {
            if (food[i] > 0) {
                sum++;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (v[i] == 0) {
                v[i] = 1;
                
            }
        }

    }
};

int main() {
    Solution().Solve();
    return 0;
}