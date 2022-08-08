#include <cstdio>
using namespace std;

int DX[4]{1, 0, -1, 0}, DY[4]{0, 1, 0, -1};

// ?

struct Solution {
    int K, X, Y, Answer = 0;
    bool B[5][5]{};

    void Solve() {
        scanf("%d", &K);
        for (int i = 0; i < K; ++i) {
            scanf("%d%d", &X, &Y);
            B[X - 1][Y - 1] = true;
        }
        Search(1, 0, 0);
        printf("%d\n", Answer);
    }

    void Search(int size, int x, int y) {
        if (x == 4 && y == 4) {
            if (size + K == 25) ++Answer;
            return;
        }
        B[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int xNew = x + DX[i];
            if (xNew < 0 || 5 <= xNew) continue;
            int yNew = y + DY[i];
            if (yNew < 0 || 5 <= yNew) continue;
            if (!B[xNew][yNew]) Search(size + 1, xNew, yNew);
        }
        B[x][y] = false;
    }
};

int main() {
    Solution().Solve();
    return 0;
}