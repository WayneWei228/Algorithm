#include <cstdio>
#include <limits>
#include <string>
#include <vector>
using namespace std;

const int N = 300;

struct Solution {
    int Input;
    vector<vector<int>> Board;

    void Solve0() {
        int maxTotal = numeric_limits<int>::min();
        int argX = -1, argY = -1;
        for (int i = 0; i < N - 2; ++i) {
            for (int j = 0; j < N - 2; ++j) {
                int total = 0;
                for (int i0 = 0; i0 < 3; ++i0) {
                    for (int j0 = 0; j0 < 3; ++j0) {
                        total += Board[i + i0][j + j0];
                    }
                }
                if (maxTotal < total) {
                    maxTotal = total;
                    argX = i;
                    argY = j;
                }
            }
        }
        printf("%d,%d\n", argX + 1, argY + 1);
    }

    void Solve1() {
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                Board[i][j] += Board[i][j - 1];
            }
        }
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                Board[i][j] += Board[i - 1][j];
            }
        }
        int maxBlockSum = numeric_limits<int>::min();
        int argX = -1, argY = -1, argZ = -1;
        for (int z = 1; z <= N; ++z) {
            for (int i = 0; i < N + 1 - z; ++i) {
                for (int j = 0; j < N + 1 - z; ++j) {
                    int a00 = i > 0 && j > 0 ? Board[i - 1][j - 1] : 0;
                    int a01 = i > 0 ? Board[i - 1][j + z - 1] : 0;
                    int a10 = j > 0 ? Board[i + z - 1][j - 1] : 0;
                    int a11 = Board[i + z - 1][j + z - 1];
                    int blockSum = a00 - a01 - a10 + a11;
                    if (maxBlockSum < blockSum) {
                        maxBlockSum = blockSum;
                        argX = i;
                        argY = j;
                        argZ = z;
                    }
                }
            }
        }
        printf("%d,%d,%d\n", argX + 1, argY + 1, argZ);
    }

    void Solve() {
        scanf("%d", &Input);
        Board.resize(N);
        for (int i = 0; i < N; ++i) {
            Board[i].resize(N);
            for (int j = 0; j < N; ++j) {
                Board[i][j] = (i + 11) * (j + 1) + Input;
                Board[i][j] = Board[i][j] * (i + 11) / 100 % 10 - 5;
            }
        }
        Solve0();
        Solve1();
    }
};

int main() {
    Solution().Solve();
    return 0;
}
