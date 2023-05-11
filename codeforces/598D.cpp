#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int DX[4]{0, -1, 0, 1}, DY[4]{1, 0, -1, 0};
/*
5 6 3
******
*..*.*
******
*....*
******
2 2
2 5
4 3
*/
struct Solution {
    int N, M, K;
    // int sum;
    vector<string> arr;
    vector<vector<bool>> visited;
    vector<vector<int>> ans;

    int DFS(int i, int j, int already) {
        int sum = already;
        int now = 0;
        if (visited[i][j]) return 0;
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int nx = i + DX[k];
            int ny = j + DY[k];
            if (nx < 0 || nx >= N) continue;
            if (ny < 0 || ny >= M) continue;
            if (arr[nx][ny] == '*') {
                now++;
            }
        }
        for (int k = 0; k < 4; k++) {
            int nx = i + DX[k];
            int ny = j + DY[k];
            if (nx < 0 || nx >= N) continue;
            if (ny < 0 || ny >= M) continue;
            if (arr[nx][ny] == '.' && !visited[nx][ny]) {
                sum += DFS(nx, ny, already + now);
            }
        }

        // cout << i << " " << j << endl;
        // cout << "sum " << sum << endl;
        ans[i][j] = sum + now;
        return now;
    }

    void Solve() {
        cin >> N >> M >> K;
        arr.resize(N);
        ans.resize(N);
        for (auto& i : ans) {
            i.resize(M);
        }
        visited.resize(N);
        for (auto& i : visited) {
            i.resize(M, 0);
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == '.' && !visited[i][j]) {
                    cout << "DFS " << i << " " << j << endl;
                    DFS(i, j, 0);
                }
            }
        }
        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            cout << ans[a - 1][b - 1] << endl;
        }
    }
};

int main() {
    freopen("output.out", "w", stdout);
    Solution().Solve();
    fclose(stdout);
    return 0;
}