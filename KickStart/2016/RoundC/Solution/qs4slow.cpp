#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

struct Soldier {
    int A, D;

    bool operator==(const Soldier& that) const {
        return A == that.A && D == that.D;
    }
};

struct SoldierHash {
    size_t operator()(const Soldier& that) const {
        return that.A * size_t(9875321) + that.D;
    }
};

struct Solution {
    int N;
    vector<Soldier> S;
    unordered_map<Soldier, bool, SoldierHash> W; // 情况/状态

    void Solve(int caseNo) {
        scanf("%d", &N);
        
        S.resize(N);
        for (Soldier& i : S) scanf("%d%d", &i.A, &i.D);
        printf("Case #%d: %s\n", caseNo, Win(0, 0) ? "YES" : "NO");
    }
    /*
    搜索 + 记忆化搜索 = 动态规划
    W 三个状态
    true 返回
    false 返回
    没定义 不管
    */
    // 迄今为止选择的最高的 攻击力 和 防御力
    // O(N * N * N) = O(N ^ 3)
    bool Win(int a, int d) {
        Soldier key{a, d};
        auto it = W.find(key);
        if (it != W.end()) return it->second;
        for (Soldier& i : S) {
            if (a < i.A || d < i.D) {
                if (!Win(max(a, i.A), max(d, i.D))) { // 对手赢不了
                    return W[key] = true; // 达到这个状态我就能赢
                }
            }
        }
        return W[key] = false;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}