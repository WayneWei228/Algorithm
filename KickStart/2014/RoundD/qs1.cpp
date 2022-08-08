#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>
#include <limits>
using namespace std;

int DX[4] {1, 0, -1, 0}, DY[4] {0, -1, 0, 1};

struct Solution {
    int N;
    vector<vector<int>> Board;
    unordered_map<int, pair<int, int>> M;
    vector<vector<int>> Visited;
    string travel;
    int num;
    void Solve(int caseNo) {
        scanf("%d", &N);
        Board.resize(N);
        Visited.resize(N);
        for (int i = 0; i < N; i++) {
            Board[i].resize(N);
            Visited[i].resize(N, -1);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &Board[i][j]);
                M[Board[i][j]] = {i, j};
            }
        }
        int R, D = numeric_limits<int>::min();
        for (int i = 1; i <= N * N; i++) {
            int a = M[i].first, b = M[i].second;
            if (Visited[a][b] == -1) {
                num = 0;
                travel = "";
                Visit(a, b);
                if (D < num) {
                    D = num;
                    R = travel[0] - '0'; // 超过9就不能 -'0'
                } else if (D == num && R > travel[0] - '0') {
                    R = travel[0] - '0';
                }
            }
        }
        printf("Case #%d: %d %d\n", caseNo, R, D);
    }

    void Visit(int i, int j) {
        travel += Board[i][j] + '0';
        Visited[i][j] = num++;
        for (int k = 0; k < 4; k++) {
            int xnew = i + DX[k];
            if (xnew < 0 || xnew >= N) continue;
            int ynew = j + DY[k];
            if (ynew < 0 || ynew >= N) continue;
            if (Board[xnew][ynew] == Board[i][j] + 1) {
                Visit(xnew, ynew);
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