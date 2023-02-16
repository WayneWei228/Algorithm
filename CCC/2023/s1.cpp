#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int DX[4]{0, -1, 0, 1};
int DY[4]{1, 0, -1, 0};

struct Solution {
    int C;
    int ans = 0;
    vector<int> arr[2];
    vector<bool> visited[2];

    int BFS(int x, int y) {
        visited[x][y] = true;
        int cnt = 1;
        pair<int, int> node = make_pair(x, y);
        queue<pair<int, int>> q;
        q.emplace(node);
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nextX = front.first + DX[i];
                int nextY = front.second + DY[i];
                if (nextX < 0 || nextX > 1 || nextY < 0 || nextY >= C)
                    continue;
                if (arr[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                    cnt++;
                    visited[nextX][nextY] = true;
                    q.emplace(make_pair(nextX, nextY));
                }
            }
        }
        return cnt * 3 - (cnt - 1) * 2;
    }

    void Solve() {
        cin >> C;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < C; j++) {
                int x;
                cin >> x;
                arr[i].push_back(x);
            }
        }
        for (auto& i : visited) {
            i.resize(C, false);
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < C; j++) {
                if (!visited[i][j] && arr[i][j] == 1) {
                    // cout << "BFS " << i << " " << j << " " << BFS(i,
                    // j)
                    //      << endl;
                    ans += BFS(i, j);
                }
            }
        }
        cout << ans << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
}