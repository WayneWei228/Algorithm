#include <cstdio>
#include <vector>
using namespace std;

int DX[4] {1, 0, -1, 0};
int DY[4] {0, 1, 0, -1};

struct Solution {
    int R, C, Rs, Cs, S;
    double P, Q, ans = 0.0;
    vector<vector<char>> grid;
    vector<vector<double>> E;

    void Solve(int caseNo) {
        scanf("%d%d%d%d%d", &R, &C, &Rs, &Cs, &S);
        scanf("%lf%lf", &P, &Q);
        grid.resize(R);
        for (auto& i : grid) {
            i.resize(C);
        }
        E.resize(R);
        for (auto& i : E) {
            i.resize(C, 1.0);
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                scanf(" %c", &grid[i][j]);
            }
        }
        Search(S, Rs, Cs, 0.0);
        printf("Case #%d: %.7lf\n", caseNo, ans);
    }

    void Search(int left, int x, int y, double current) {
        if (left == 0) {
            if (current > ans) {
                ans = current;
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xnew = x + DX[i];
            if (xnew < 0 || xnew >= R) continue;
            int ynew = y + DY[i];
            if (ynew < 0 || ynew >= C) continue;
            double p = (grid[xnew][ynew] == '.') ? Q : P;
            double e = E[xnew][ynew];
            double next = current + e * p;
            E[xnew][ynew] *= 1 - p; // E[xnew][ynew] = E[xnew][ynew] - E[xnew][ynew] * p;
            Search(left - 1, xnew, ynew, next);
            E[xnew][ynew] = e;
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}