
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

// 16进制
int B[4][7] = { // B[rotate][type]
    {0x0132, 0x0231, 0x0113, 0x0223, 0x0033, 0x1111, 0x0027},
    {0x0063, 0x0036, 0x0047, 0x0074, 0x0033, 0x000f, 0x0232},
    {0x0132, 0x0231, 0x0322, 0x0311, 0x0033, 0x1111, 0x0072},
    {0x0063, 0x0036, 0x0071, 0x0017, 0x0033, 0x000f, 0x0131},
};

/*
0x0132:
0000
1000
1100
0100

0x0231:
0000
0100
1100
1000

0x0033:
0000
0000
1100
1100
*/

struct Solution {
    int W, H, N;
    vector<vector<bool>> Board;
    vector<int> F;
    bool Over = false;

    void Solve(int caseNo) {
        scanf("%d%d%d", &W, &H, &N);
        Board.resize(H);
        for (auto& i : Board) i.resize(W);
        F.resize(H);
        for (int i = 0; i < N; ++i) {
            int t, r, x;
            scanf("%d%d%d", &t, &r, &x);
            int v = H, b = B[r][t - 1];
            while (0 < v && Pass(v - 1, b, x)) --v; // 从上到下往下落，只要还能落就继续落
            if (Overflow(v, b)) {
                Over = true;
            } else {
                AddToBoard(v, b, x);
            }
        }
        printf("Case #%d:\n", caseNo);
        if (Over) {
            printf("Game Over!\n");
        } else {
            for (int i = H - 1; i >= 0; --i) {
                for (bool j : Board[i]) printf(j ? "x" : ".");
                printf("\n");
            }
        }
    }

    // 放在图上跟别人不重叠
    /*
        v: 纵的偏移量
        x: 横的偏移量
        b: 图形
    */
    bool Pass(int v, int b, int x) { 
        int mask = 0;
        for (int i = 0; i < 4; ++i) {
            if (H <= v + i) break; // Board 0 -- H - 1
            for (int j = 0; j < 4; ++j) {
                // 对bool型左移是先变成整数再左移
                mask |= Board[v + i][x + j] << (i * 4 + j);
            }
        }
        return (mask & b) == 0; // 有交集就不行
    }

    bool Overflow(int v, int b) {
        int a = H - v; // 在图里能放下b的几行
        return a < 4 && (b >> a * 4) != 0; // 先乘除
        // 移走a行看剩下行是否为0
    }

    void AddToBoard(int v, int b, int x) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if ((b >> (i * 4 + j)) & 1) {
                    Board[v + i][x + j] = true;
                    ++F[v + i];
                }
            }
        }
        vector<vector<bool>> newBoard;
        vector<int> newF;
        for (int i = 0; i < H; ++i) {
            if (F[i] == W) continue;
            newBoard.emplace_back();
            swap(newBoard.back(), Board[i]);
            newF.emplace_back(F[i]);
        }
        while (newF.size() < H) {
            newBoard.emplace_back();
            newBoard.back().resize(W);
            newF.emplace_back(0);
        }
        swap(Board, newBoard);
        swap(F, newF);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}
