#include <cstdio>
#include <limits>
#include <string>
#include <vector>
using namespace std;

char Buffer[80];

struct Solution {
    vector<vector<int>> D;

    void Solve() {
        D.resize(8);
        for (int i = 0; i < 8; ++i) D[i].resize(256);
        while (true) {
            if (scanf("%s", Buffer) < 1) break;
            for (int i = 0; i < 8; ++i) ++D[i][Buffer[i]];
        }
        string answer1(8, '_'), answer2(8, '_');
        for (int i = 0; i < 8; ++i) {
            int minD = numeric_limits<int>::max();
            int maxD = numeric_limits<int>::min();
            char argminD, argmaxD;
            for (int j = 0; j < 256; ++j) {
                if (0 < D[i][j] && D[i][j] < minD) {
                    minD = D[i][j];
                    argminD = j;
                }
                if (0 < D[i][j] && maxD < D[i][j]) {
                    maxD = D[i][j];
                    argmaxD = j;
                }
            }
            answer1[i] = argmaxD;
            answer2[i] = argminD;
        }
        printf("%s\n", answer1.c_str());
        printf("%s\n", answer2.c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
