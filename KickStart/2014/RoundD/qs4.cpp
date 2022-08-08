#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int DXhv[4]{1, 0, -1, 0}, DYhv[4]{0, -1, 0, 1};
int DXd[4]{1, 1, -1, -1}, DYd[4]{1, -1, -1, 1};
int DXN[8]{2, 2, 1, -1, -2, -2, -1, 1},
    DYN[8]{1, -1, -2, -2, -1, 1, 2, 2};
struct Game {
    int ans = 0;
    vector<string> Board;
    Game() {
        Board.resize(8);
        for (auto& i : Board) {
            i.resize(8, '.');
        }
    }

    void Run() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (Board[i][j] != '.') {
                    goKill(i, j);
                }
            }
        }
    }

    void goKill(int x, int y) {
        switch (Board[x][y]) {
            case 'K': {
                Killd(x, y, 1);
                Killhv(x, y, 1);
                break;
            }
            case 'Q': {
                Killd(x, y, 15);
                Killhv(x, y, 15);
                break;
            }
            case 'R': {
                Killhv(x, y, 15);
                break;
            }
            case 'B': {
                Killd(x, y, 15);
                break;
            }
            case 'N': {
                for (int i = 0; i < 8; i++) {
                    int xnew = x + DXN[i];
                    if (xnew < 0 || xnew >= 8) continue;
                    int ynew = y + DYN[i];
                    if (ynew < 0 || ynew >= 8) continue;
                    if (Board[xnew][ynew] != '.') {
                        ans++;
                        break;
                    }
                }
            }
            case 'P': {
                int xnew = x - 1, ynew = y - 1;
                if (xnew >= 0 && xnew < 8 && ynew >= 0 && ynew < 8) {
                    if (Board[xnew][ynew] != '.') ans++;
                }
                xnew = x + 1, ynew = y - 1;
                if (xnew >= 0 && xnew < 8 && ynew >= 0 && ynew < 8) {
                    if (Board[xnew][ynew] != '.') ans++;
                }
                break;
            }
            default: break;
        }
    }

    void Killd(int x, int y, int steps) {
        for (int i = 0; i < 4; i++) {
            for (int k = 0; k < steps; k++) {
                int xnew = x + DXd[i] + k;
                if (xnew < 0 || xnew >= 8) continue;
                int ynew = y + DYd[i] + k;
                if (ynew < 0 || ynew >= 8) continue;
                if (Board[xnew][ynew] != '.') {
                    ans++;
                    break;
                }
            }
        }
    }

    void Killhv(int x, int y, int steps) {
        for (int i = 0; i < 4; i++) {
            for (int k = 0; k < steps; k++) {
                int xnew = x + DXhv[i] + k;
                if (xnew < 0 || xnew >= 8) continue;
                int ynew = y + DYhv[i] + k;
                if (ynew < 0 || ynew >= 8) continue;
                if (Board[xnew][ynew] != '.') {
                    ans++;
                    break;
                }
            }
        }
    }
};

struct Solution {
    int N;
    Game G;
    void Solve(int caseNo) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            char col, type;
            int row;
            scanf(" %c%d-%c", &col, &row, &type);
            G.Board[row - 1]['H' - col] = type;
        }
        G.Run();
        printf("Case #%d: %d\n", caseNo, G.ans);

    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}