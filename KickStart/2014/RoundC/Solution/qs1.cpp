#include <cstdio>
#include <functional>
#include <string>
#include <vector>
using namespace std;

char Buffer[301];

int DX[8]{1, 1, 0, -1, -1, -1, 0, 1};
int DY[8]{0, 1, 1, 1, 0, -1, -1, -1};

struct Solution {
    int N;
    vector<string> B;

    void Solve(int caseNo) {
        scanf("%d", &N);
        B.resize(N);
        for (int i = 0; i < N; ++i) {
            scanf("%s", Buffer);
            B[i] = Buffer;
        }
        ForB([&](int x, int y) {
            if (B[x][y] == '.') B[x][y] = Near(x, y);
        });
        int answer = 0;
        ForB([&](int x, int y) {
            if (B[x][y] != '0') return;
            Visit(x, y);
            ++answer;
        });
        ForB([&](int x, int y) {
            if (B[x][y] != '.' && B[x][y] != '*') ++answer;
        });
        printf("Case #%d: %d\n", caseNo, answer);
    }

    void ForB(function<void(int, int)> f) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) f(i, j);
        }
    }

    void ForNeighbors(int x, int y, function<void(int, int)> f) {
        for (int i = 0; i < 8; ++i) {
            int nearX = x + DX[i];
            int nearY = y + DY[i];
            if (nearX < 0 || N <= nearX) continue;
            if (nearY < 0 || N <= nearY) continue;
            f(nearX, nearY);
        }
    }

    char Near(int x, int y) {
        int answer = 0;
        ForNeighbors(x, y, [&](int nX, int nY) {
            if (B[nX][nY] == '*') ++answer;
        });
        return '0' + answer;
    }

    void Visit(int x, int y) {
        B[x][y] = '.';
        ForNeighbors(x, y, [&](int nX, int nY) {
            char b = B[nX][nY];
            if (B[nX][nY] != '*') B[nX][nY] = '.';
            if (b == '0') Visit(nX, nY);
        });
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}
 