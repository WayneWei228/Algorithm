#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int DX[4]{1, 0, -1, 0}, DY[4]{0, 1, 0, -1};

// 步数有限
// 图太大，不可压缩
// DFS回溯 单线程搜索

struct Solution {
    int R, C, RS, CS, S;
    double P, Q, Answer = 0.0;
    vector<string> Board;
    vector<vector<double>> E;

    void Solve(int caseNo) {
        scanf("%d%d%d%d%d%lf%lf", &R, &C, &RS, &CS, &S, &P, &Q);
        Board.resize(R);
        for (auto& i : Board) {
            i.resize(C, '.');
            for (auto& j : i) scanf(" %c", &j);
        }
        E.resize(R);
        for (auto& i : E) i.resize(C, 1.0);
        Search(S, RS, CS, 0.0);
        printf("Case #%d: %.7lf\n", caseNo, Answer);
    }

    void Search(int s, int r, int c, double current) {
        if (s == 0) {
            if (Answer < current) Answer = current;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int newX = r + DX[i], newY = c + DY[i];
            if (newX < 0 || R <= newX) continue;
            if (newY < 0 || C <= newY) continue;
            double p = Board[newX][newY] == 'A' ? P : Q;
            double next = current + E[newX][newY] * p;
            double e = E[newX][newY];
            E[newX][newY] *= 1 - p; // E[xnew][ynew] = E[xnew][ynew] - E[xnew][ynew] * p;
            Search(s - 1, newX, newY, next);
            E[newX][newY] = e;
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}