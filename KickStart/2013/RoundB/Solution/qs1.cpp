#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;

struct Solution {
    int N;
    vector<unordered_set<int>> S[3];

    void Solve(int caseNo) {
        scanf("%d", &N);
        printf("Case #%d: %s\n", caseNo, ReadTest() ? "Yes" : "No");
    }

    bool ReadTest() {
        for (auto& i : S) i.resize(N * N);
        auto add = [this](int r, int iH, int iL, int x) {
            // iH * N + iL 为 序号
            return S[r][iH * N + iL].emplace(x).second;
        };
        bool success = true;
        // 行中第几块
        for (int i0 = 0; i0 < N; ++i0) {
            // 块中第几个 行*
            for (int i1 = 0; i1 < N; ++i1) {
                // 列中第几块
                for (int i2 = 0; i2 < N; ++i2) {
                    // 块中第几个 列*
                    for (int i3 = 0; i3 < N; ++i3) {
                        int x;
                        scanf("%d", &x);
                        // x 在范围内
                        success &= 1 <= x && x <= N * N;
                        success &= add(0, i0, i1, x);
                        success &= add(1, i2, i3, x);
                        success &= add(2, i0, i2, x);
                    }
                }
            }
        }
        return success;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}