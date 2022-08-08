#include <cstdio>
#include <limits>
#include <vector>
using namespace std;

struct Solution {
    int serial;
    vector<vector<int>> M;

    void Solve() {
        scanf("%d", &serial);
        M.resize(301);
        for (auto& i : M) {
            i.resize(301);
        }
        for (int i = 0; i <= 300; i++) {
            M[i][0] = M[0][i] = 0;
        }
        for (int y = 1; y <= 300; y++) {
            for (int x = 1; x <= 300; x++) {
                int id = x + 10;
                int power = (id * y + serial) * id / 100 % 10 - 5;
                M[y][x] = power;
            }
        }
        int ans1 = numeric_limits<int>::min();
        int arg_x = -1;
        int arg_y = -1;
        for (int y = 1; y <= 298; y++) {
            for (int x = 1; x <= 298; x++) {
                int total = 0;
                for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < 3; b++) {
                        total += M[y + a][x + b];
                    }
                }
                if (total > ans1) {
                    ans1 = total;
                    arg_x = x;
                    arg_y = y;
                }
            }
        }
        printf("%d,%d\n", arg_x, arg_y);
        for (int i = 0; i <= 300; i++) {
            for (int j = 0; j <= 300; j++) {
                if (i == 0) continue;
                if (j == 0) continue;
                M[i][j] += M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1];
            }
        }
        int ans2 = numeric_limits<int>::min();
        int arg2x = -1;
        int arg2y = -1;
        int size = -1;
        for (int k = 1; k <= 300; k++) {
            for (int y = 1; y < 302 - k; y++) {
                for (int x = 1; x < 302 - k; x++) {
                    int total = 0;
                    total = M[y + k - 1][x + k - 1] -
                            M[y + k - 1][x - 1] - M[y - 1][x + k - 1] +
                            M[y - 1][x - 1];
                    if (total > ans2) {
                        ans2 = total;
                        arg2x = x;
                        arg2y = y;
                        size = k;
                    }
                }
            }
        }
        printf("%d,%d,%d\n", arg2x, arg2y, size);
    }
};

int main() {
    Solution().Solve();
    return 0;
}