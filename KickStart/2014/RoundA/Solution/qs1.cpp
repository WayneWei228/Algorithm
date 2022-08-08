#include <cstdio>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

char Buffer[80];

unordered_map<string, int> R{
    {"left", 0},
    {"up", 1},
    {"right", 2},
    {"down", 3},
};

struct Solution {
    int N;
    vector<vector<int>> B;

    void Solve(int caseNo) {
        scanf("%d%s", &N, Buffer);
        int r = R[Buffer];
        B.resize(N);
        for (auto& i : B) {
            i.resize(N);
            for (int& j : i) scanf("%d", &j);
        }
        for (int i = 0; i < r; i++) Rotate90();
        PushLeft();
    }

    void Rotate90() {
        vector<vector<int>> newB = B;
        // 逆时针90度
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                newB[N - 1 - j][i] = B[i][j];
            }
        }
        swap(B, newB);
    }

    void PushLeft() {
        vector<vector<int>> newB(N);
        for (int i = 0; i < N; ++i) {
            newB[i].resize(N);
            // 反思：当碰到遍历数组两个两个比较的时候
            // 不妨开个变量存储第一次碰到的值
            // 这样可以不用担心越界问题且还是O(n)
            int size = 0, b0 = 0; 
            for (int j : B[i]) {
                if (j == 0) continue;
                if (j == b0) {
                    newB[i][size++] = j + b0;
                    b0 = 0;
                    continue;
                }
                if (b0 != 0) newB[i][size++] = b0;
                b0 = j;
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