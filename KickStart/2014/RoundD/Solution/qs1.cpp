#include <cstdio>
#include <vector>
using namespace std;

int DX[4]{1, 0, -1, 0}, DY[4]{0, 1, 0, -1};

// 动态规划: 递推 和 记忆化搜索
// 记忆化搜索

/*
递推:
9 为 1
判断当前点四周有没有连着的
有则 连着的 + 1
无则 1

记忆化搜索：
先写搜索
再加Cache （L[x][y]
搜索前判断有无搜过（cache原理
*/
struct Solution {
    int N;
    vector<vector<int>> B, L;

    void Solve(int caseNo) {
        scanf("%d", &N);
        B.resize(N);
        for (auto& i : B) {
            i.resize(N);
            for (int& j : i) scanf("%d", &j);
        }
        L.resize(N);
        for (auto& i : L) i.resize(N);
        int answer = 0, arg = -1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (answer < ComputeL(i, j)) {
                    answer = L[i][j];
                    arg = B[i][j];
                } else if (answer == L[i][j]) {
                    if (B[i][j] < arg) arg = B[i][j];
                }
            }
        }
        printf("Case #%d: %d %d\n", caseNo, arg, answer);
    }
    // cache 缓存
    // 把算过的东西存下来不用再算，起到加速作用
    // L[x][y] 存 ComputeL
    int ComputeL(int x, int y) { // 返回当前位置所能走过的最多块数
        if (L[x][y] != 0) return L[x][y];
        L[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nextX = x + DX[i];
            if (nextX < 0 || N <= nextX) continue;
            int nextY = y + DY[i];
            if (nextY < 0 || N <= nextY) continue;
            if (B[x][y] + 1 == B[nextX][nextY]) {
                L[x][y] = max(L[x][y], ComputeL(nextX, nextY) + 1);
            }
        }
        return L[x][y];
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}