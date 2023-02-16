#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Solution {
    int C;
    int ans = 0;
    vector<int> arr[2];
    vector<bool> visited[2];

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
        // first row
        for (int i = 0; i < C; i++) {
            int cnt = 3;
            int nx, ny;
            if (!arr[0][i]) continue;
            if (i % 2 == 0) {
                nx = 0, ny = i - 1;
                if (0 <= ny && ny < C && arr[nx][ny]) cnt--;
                nx = 0, ny = i + 1;
                if (0 <= ny && ny < C && arr[nx][ny]) cnt--;
                nx = 1, ny = i;
                if (0 <= ny && ny < C && arr[nx][ny]) cnt--;
            } else {
                nx = 0, ny = i - 1;
                if (0 <= ny && ny < C && arr[nx][ny]) cnt--;
                nx = 0, ny = i + 1;
                if (0 <= ny && ny < C && arr[nx][ny]) cnt--;
            }
            ans += cnt;
        }
        // cout << " First Row " << ans << endl;
        for (int i = 0; i < C; i++) {
            int cnt = 3;
            int nx, ny;
            if (!arr[1][i]) continue;
            if (i % 2 == 0) {
                nx = 1, ny = i - 1;
                if (0 <= ny && ny < C && arr[nx][ny]) cnt--;
                nx = 1, ny = i + 1;
                if (0 <= ny && ny < C && arr[nx][ny]) cnt--;
                nx = 0, ny = i;
                if (0 <= ny && ny < C && arr[nx][ny]) cnt--;
            } else {
                nx = 1, ny = i - 1;
                if (0 <= ny && ny < C && arr[nx][ny]) cnt--;
                nx = 1, ny = i + 1;
                if (0 <= ny && ny < C && arr[nx][ny]) cnt--;
            }
            ans += cnt;
        }
        cout << ans << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
}