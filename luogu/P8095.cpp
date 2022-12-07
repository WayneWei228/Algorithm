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
    int e[100020];
    vector<int> o;
    vector<int> z;
    queue<int> q;
    int sum = 0;
    void Solve() {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            cin >> x[i] >> y[i];
            food[x[i]]++;  // 出度
            food[y[i]]++;
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
                    z.push_back(next.second);
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
                o.push_back(i);
                food[x[i]]--;
                food[y[i]]--;
                if (food[y[i]] == 1) {
                    q.push(y[i]);
                }
                while (q.size()) {
                    int u = q.front();
                    q.pop();
                    for (pair<int, int> i : W[u]) {
                        if (v[i.second] == 0) {
                            food[u]--;
                            food[i.first]--;
                            if (food[i.first] == 1) {
                                q.push(i.first);
                            }
                            z.push_back(i.second);
                            v[i.second] = 1;
                        }
                    }
                }
                e[x[i]] = 1;
                q.push(x[i]);
                // BFS
                while (q.size()) {
                    int u = q.front();
                    q.pop();
                    for (pair<int, int> i : W[u]) {
                        if (v[i.second] == 0) {
                            v[i.second] = 1;
                            o.push_back(i.second);
                            if (e[i.first] == 0) {
                                e[i.first] = 1;
                                q.push(i.first);
                            }
                        }
                    }
                }
            }
        }
        cout << N - sum << endl;
        for (int i = 0; i < o.size(); i++) {
            cout << o[i] << endl;
        }
        for (int i = z.size() - 1; i >= 0; i--) {
            cout << z[i] << endl;
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}