#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[80];

int Next[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

struct Circular {
    int origin[256], no = 0, skipsize = 0;
    int size = 256;

    Circular() {
        for (int i = 0; i < 256; i++) origin[i] = i;
    }

    void Do(int len) {
        int radius = len / 2;
        int left = no, right = (no + len - 1) % size;
        if (len > size) goto Move;
        for (int i = 0; i < radius; ++i) {
            swap(origin[left++ % size],
                 origin[(size + right--) % size]);
        }
    Move:
        no = (no + len + skipsize++) % size;
    }
};

string KnotHash(string&& s) {
    Circular c;
    string out = "";
    s += "\x11\x1f\x49\x2f\x17";
    for (int i = 0; i < 64; i++) {
        for (char j : s) {
            c.Do(j);
        }
    }
    int k = 0;
    for (int i = 0; i < 16; i++) {
        int dense = 0;
        for (int j = 0; j < 16; j++) {
            dense ^= c.origin[k++];
        }
        // 十六进制转二进制再放入字符串
        // 由 7 到 0
        // 使得out里为正向binary
        for (int k = 7; k >= 0; k--) {
            out += '0' + ((dense >> k) & 1);
        }
    }
    return out;
}

struct Solution {
    int ans1 = 0;
    vector<string> grid;
    vector<vector<bool>> visited;

    void fill(int x, int y) {
        if (visited[x][y]) return;
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int next_x = x + Next[i][0];
            if (next_x < 0 || next_x > 127) continue;
            int next_y = y + Next[i][1];
            if (next_y < 0 || next_y > 127) continue;
            if (!visited[next_x][next_y] &&
                grid[next_x][next_y] == '#') {
                fill(next_x, next_y);
            }
        }
    }

    void Solve() {
        scanf("%s", Buffer);
        string s = Buffer;
        grid.resize(128);
        for (int i = 0; i < 128; i++) {
            string temp = s;
            temp += "-";
            temp += to_string(i);
            string line = KnotHash(move(temp)).c_str();
            for (int k = 0; k < 128; k++) {
                if (line[k] == '1') {
                    ans1++;
                    grid[i] += "#";
                } else {
                    grid[i] += ".";
                }
            }
        }
        int regions = 0;
        visited.resize(128);
        for (auto& i : visited) i.resize(128);
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                if (grid[i][j] == '#' && !visited[i][j]) {
                    fill(i, j);
                    regions++;
                }
            }
        }

        printf("%d\n", ans1);
        printf("%d\n", regions);
    }
};

int main() {
    Solution().Solve();
    return 0;
}