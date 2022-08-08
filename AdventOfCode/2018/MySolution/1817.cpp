#include <unistd.h>

#include <cstdio>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Solution {
    vector<vector<char>> Input;
    int MaxX = numeric_limits<int>::min();
    int MinX = numeric_limits<int>::max();
    void Fall(int x, int y) {
        int top = x;
        Input[x][y] = '|';
        while (true) {
            if (x++ >= MaxX + 10) return;
            if (Input[x][y] == '|') return;
            if (Input[x][y] != '.') break;
            Input[x][y] = '|';
        }
        x--;
        bool fl = false, fr = false;
        int ly = y, ry = y;
        while (!fl && !fr && x >= top - 1) {
            fl = false, fr = false;
            Input[x][y] = '~';
            ly = y, ry = y;
            while (Input[x][++ry] == '.') {
                Input[x][ry] = '~';
                if (Input[x + 1][ry] == '.') {
                    Fall(x + 1, ry);
                    fr = true;
                    break;
                }
            }
            while (Input[x][--ly] == '.') {
                Input[x][ly] = '~';
                if (Input[x + 1][ly] == '.') {
                    Fall(x + 1, ly);
                    fl = true;
                    break;
                }
            }
            if (fr && Input[x][ry + 1] == '~') fr = false;
            if (fl && Input[x][ly - 1] == '~') fl = false;
            x--;
        }
        x++;
        if (fl || fr) {
            for (int j = ly; j <= ry; j++) {
                if (Input[x][j] == '~') {
                    Input[x][j] = '|';
                }
            }
        }
        return;
    }

    void Solve() {
        Input.resize(2022);
        for (auto& i : Input) {
            i.resize(2022, '.');
        }
        while (true) {
            char a, b;
            int l, f, t;
            if (scanf("%c=%d, %c=%d..%d ", &a, &l, &b, &f, &t) < 5)
                break;
            for (int i = f; i <= t; i++) {
                (a == 'x') ? Input[i][l] = '#' : Input[l][i] = '#';
                if (a == 'y') {
                    if (l > MaxX) MaxX = l;
                    if (l < MinX) MinX = l;
                }
                if (b == 'y') {
                    if (f < MinX) MinX = f;
                    if (t < MinX) MinX = t;
                    if (f > MaxX) MaxX = f;
                    if (t > MaxX) MaxX = t;
                }
            }
        }
        Fall(0, 500);
        Input[0][500] = '+';
        int willdry = 0;
        int notdry = 0;
        for (int i = MinX; i <= MaxX; i++) {
            for (int j = 0; j < Input[i].size(); j++) {
                if (Input[i][j] == '~') notdry++;
                if (Input[i][j] == '|') willdry++;
            }
        }
        printf("%d\n", notdry + willdry);
        printf("%d\n", notdry);
    }
};

int main() {
    Solution().Solve();
    return 0;
}