#include <cstdio>
#include <memory>
#include <string>
#include <vector>
using namespace std;

char Buffer[80];

struct Solution {
    vector<string> B;

    void Solve() {
        B.resize(6);
        for (int i = 0; i < 6; ++i) B[i].resize(50, '.');
        while (scanf("%[^\n]\n", Buffer) == 1) {
            string s = Buffer;
            int x, y, offset;
            if (sscanf(s.c_str(), "rotate row y=%d by %d", &y,
                       &offset) == 2) {
                string b(50, 0);
                for (int i = 0; i < 50; ++i) b[i] = B[y][i];
                for (int i = 0; i < 50 - offset; ++i) {
                    B[y][i + offset] = b[i];
                }
                for (int i = 50 - offset; i < 50; ++i) {
                    B[y][i + offset - 50] = b[i];
                }
            }
            if (sscanf(s.c_str(), "rotate column x=%d by %d", &x,
                       &offset) == 2) {
                string b(6, 0);
                for (int i = 0; i < 6; ++i) b[i] = B[i][x];
                for (int i = 0; i < 6 - offset; ++i) {
                    B[i + offset][x] = b[i];
                }
                for (int i = 6 - offset; i < 6; ++i) {
                    B[i + offset - 6][x] = b[i];
                }
            }
            if (sscanf(s.c_str(), "rect %dx%d", &x, &y)) {
                for (int i = 0; i < y; ++i) {
                    for (int j = 0; j < x; ++j) B[i][j] = '#';
                }
            }
        }
        int answer = 0;
        for (const auto& i : B) {
            for (char j : i) answer += j == '#';
        }
        printf("%d\n", answer);
        for (const auto& i : B) printf("%s\n", i.c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}