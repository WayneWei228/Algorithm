#include <cstdio>
#include <vector>
using namespace std;

typedef long long int64;

struct Solution {
    int R, C, K;
    vector<vector<int>> grid;
    int64 ans = 0;
    void Solve(int caseNo) {
        scanf("%d%d%d", &R, &C, &K);
        grid.resize(R);
        for (auto& i : grid) {
            i.resize(C);
        }
        for (int i = 0; i < K; i++) {
            int r, c;
            scanf("%d%d", &r, &c);
            grid[r][c] = 1;
        }
        vector<int> count(C);
        for (int i = 0; i < R; i++) {
            vector<int> newCount(C);
            for (int j = 0; j < C; j++) {
                if (!grid[i][j]) newCount[j] = count[j] + 1;
            }
            int MaxC = *max_element(newCount.begin(), newCount.end());
            vector<vector<int>> partial;
            partial.resize(MaxC + 1);
            for (int j = 0; j < C; j++) {
                for (int k = 1; k <= newCount[j]; k++) {
                    if (!partial.empty() && partial[k].back() != j - 1) {
                        partial[k].clear();
                    }
                    partial[k].emplace_back(j);
                    if (partial[k].size() == j) {
                        ans++;
                        partial[k].erase(partial[k].begin());
                    }
                }
            }
            swap(count, newCount);
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}