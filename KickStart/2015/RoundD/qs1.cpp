#include <cstdio>
#include <vector>
using namespace std;

int DX[4]{0, 1, 0, -1}, DY[4]{1, 0, -1, 0};

struct Solution {
    int R, C, N;
    vector<vector<int>> grid;
    vector<vector<bool>> Visited;
    void Travel(int x, int y) {
        if (Visited[x][y]) return;
        Visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int xnew = x + DX[i];
            if (xnew < 0 || xnew >= R) continue;
            int ynew = y + DY[i];
            if (ynew < 0 || ynew >= C) continue;
            if (Visited[xnew][ynew]) continue;
            if (grid[xnew][ynew]) {
                Travel(xnew, ynew);
            }
        }
        return;
    }

    int FindNumberofAreas() {
        int ans = 0;
        for (auto& i : Visited) {
            i.clear();
            i.resize(C);
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] && !Visited[i][j]) {
                    Travel(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void Solve(int caseNo) {
        scanf("%d%d", &R, &C);
        grid.resize(R);
        for (auto& i : grid) i.resize(C);
        Visited.resize(R);
        for (auto& i : Visited) i.resize(C);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                char d; // int d read 101
                scanf(" %c", &d);
                grid[i][j] = d - '0';
            }
        }
        printf("Case #%d:\n", caseNo);
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            char oper;
            scanf(" %c", &oper);
            if (oper == 'Q') {
                printf("%d\n", FindNumberofAreas());
            } else {
                int x, y, z;
                scanf("%d%d%d", &x, &y, &z);
                grid[x][y] = z;
            }
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}