#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[200];
int Next[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Solution {
    vector<string> map;
    int xSize, ySize;
    string output1 = "";
    vector<vector<bool>> visited;
    int ans2 = 0;
    void Go(int x, int y, int d) {
        if (isalpha(map[x][y])) {
            output1 += map[x][y];
        }
        ans2++;
        for (int i = 0; i < 4; i++) {
            if (i == 2) continue;
            int dir = (d + i) % 4;
            int xNext = x + Next[dir][0];
            int yNext = y + Next[dir][1];
            if (0 <= xNext && xNext < xSize && 0 <= yNext &&
                yNext < ySize && map[xNext][yNext] != ' ') {
                Go(xNext, yNext, dir);
                break;
            }
        }
        return;
    }

    void Solve() {
        while (scanf("%[^\n]%*c", Buffer) == 1) {  // \n 会把下一行开头的空格吃掉
                                                   // 读一次 \n ' ' \t 都会一次吃掉所有空白符
            string s = Buffer;
            map.emplace_back(s);
        }
        xSize = int(map.size());
        ySize = int(map[0].size());
        int startY;
        for (int i = 0; i < ySize; i++) {
            if (map[0][i] == '|') {
                startY = i;
                break;
            }
        }
        Go(0, startY, 0);
        printf("%s\n", output1.c_str());
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}