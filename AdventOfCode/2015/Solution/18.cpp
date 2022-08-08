#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int N = 100;

char Buffer[101];

struct Board {
    vector<string> A;
    bool CornerFixed;

    int Near9(int x, int y) {
        int lowerX = max(0, x - 1);
        int lowerY = max(0, y - 1);
        int upperX = min(N - 1, x + 1);
        int upperY = min(N - 1, y + 1);
        int answer = 0;
        for (int i = lowerX; i <= upperX; ++i) {
            for (int j = lowerY; j <= upperY; ++j) {
                if (A[i][j] == '#') ++answer;
            }
        }
        return answer;
    }

    void Next() {
        if (CornerFixed) FixCorner();
        vector<string> next(A);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int near = Near9(i, j);
                if (A[i][j] == '#') {
                    next[i][j] = (near == 3 || near == 4) ? '#' : '.';
                } else {
                    next[i][j] = (near == 3) ? '#' : '.';
                }
            }
        }
        A = move(next);
        if (CornerFixed) FixCorner();
    }

    void FixCorner() {
        A[0][0] = A[0][N - 1] = A[N - 1][0] = A[N - 1][N - 1] = '#';
    }

    int Count() {
        int answer = 0;
        for (const auto& i : A) {
            for (const auto& j : i) {
                if (j == '#') ++answer;
            }
        }
        return answer;
    }
};

struct Solution {
    vector<string> A;

    void Solve() {
        for (int i = 0; i < 100; ++i) {
            scanf("%s", Buffer);
            A.emplace_back(Buffer);
        }
        Board B1{A, false};
        for (int i = 0; i < 100; ++i) B1.Next();
        printf("%d\n", B1.Count());
        Board B2{A, true};
        for (int i = 0; i < 100; ++i) B2.Next();
        printf("%d\n", B2.Count());
    }
};

int main() {
    Solution().Solve();
    return 0;
}