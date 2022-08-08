#include <cstdio>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[80];
// 50/41
// 19/43
typedef unsigned long long uint64;

struct Bridge {
    int sum;
    bool visited = false;
};

struct Solution {
    vector<vector<int>> M;
    vector<Bridge> bridges;

    int ans1 = numeric_limits<int>::min();
    int ans2 = numeric_limits<int>::min();
    int path = 0;
    void Go(int no, int sum, int len) {
        if (sum > ans1) ans1 = sum;
        if (len > path) {
            ans2 = sum;
            path = len;
        } else if (len == path && sum > ans2) {
            ans2 = sum;
        }
        for (auto i : M[no]) {
            Bridge& e = bridges[i];
            if (e.visited) continue;
            e.visited = true;
            Go(e.sum - no, sum + e.sum, len + 1);
            e.visited = false;
        }
    }

    void Solve() {
        while (true) {
            int l, r;
            if (scanf("%d/%d\n", &l, &r) != 2) break;
            bridges.emplace_back(Bridge{l + r});
            if (M.size() <= l) M.resize(l + 1);
            if (M.size() <= r) M.resize(r + 1);
            // 此pair在bridges中的下标
            M[l].emplace_back(bridges.size() - 1);
            M[r].emplace_back(bridges.size() - 1);
        }
        Go(0, 0, 0);

        printf("%d\n", ans1);
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}