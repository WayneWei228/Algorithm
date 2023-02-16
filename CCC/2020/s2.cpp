#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Solution {
    int M, N;
    vector<vector<int>> grid;
    vector<vector<bool>> visited;

    void DFS(int x, int y) {
        if (x >= M || x < 0 || y >= N || y < 0) {
            return;
        }
        if (visited[x][y]) {
            return;
        }
        int v = grid[x][y];
        visited[x][y] = true;

        for (int i = 1; i <= M; i++) {
            if (v % i != 0) continue;
            int nextX = i - 1;
            int nextY = v / i - 1;
            DFS(nextX, nextY);        
        }
        // for (int i = 1; i * i <= v; i++) {
        //     if (v % i != 0) continue;
        //     int nextX = i - 1;
        //     int nextY = v / i - 1;
        //     DFS(nextX, nextY);
        //     swap(nextX, nextY);
        //     DFS(nextX, nextY);
        // }
    }
    void Solve() {
        cin >> M >> N;
        grid.resize(M);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int x;
                cin >> x;
                grid[i].push_back(x);
            }
        }
        visited.resize(M);
        for (auto& i : visited) {
            i.resize(N, 0);
        }
        DFS(0, 0);
        string ans = (visited[M - 1][N - 1] == true) ? "yes" : "no";
        cout << ans << endl;
        // for (int i = 0; i < M; i++) {
        //     for (int j = 0; j < N; j++) {
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
};

int main() {
    Solution().Solve();
    return 0;
}