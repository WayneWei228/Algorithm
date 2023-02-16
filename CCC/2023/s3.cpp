#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Solution {
    int N, M, R, C;
    vector<string> grid;
    void Solve() {
        cin >> N >> M >> R >> C;
        grid.resize(N);
        for (auto& i : grid) {
            i.resize(M);
        }
        for (int j = 0; j < C; j++) {
            grid[0][j] = 'a';
            grid[1][j] = 'a';
        }
        for (int i = 0; i < R; i++) {
            char letter = 'a';
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == letter) {
                    grid[i][M - j - 1] = grid[i][j];
                } else {
                    letter = (letter + 1) % 'a';
                    grid[i][M - j - 1] = grid[i][j] = letter;
                }
            }
        }
        // for (int i = R; i < N; i++) {
            
        // }
    }
};

int main() {
    Solution().Solve();
    return 0;
}