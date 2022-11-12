#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/*
只用考虑 第 i 人喜欢分配 i 之前的东西
传递闭包x x x
*/

int a[505][505];
bitset<505> g[505];
struct Solution {
    int N;

    void Solve() {
        cin >> N;

        for (int i = 1; i <= N; i++) {
            bool f = true;
            for (int j = 1; j <= N; j++) {
                cin >> a[i][j];
                if (f) {
                    g[a[i][j]][i] = true;  // a[i][j] 可以换 i
                }
                if (a[i][j] == i) {
                    f = false;
                }
            }
        }
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                if (g[i][k]) {
                    g[i] |= g[k];
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (g[i][a[i][j]]) {  // 对于 i ，最想要的是a[i][1],
                                      // 看能不能换
                    cout << a[i][j] << endl;
                    break;
                }
            }
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}