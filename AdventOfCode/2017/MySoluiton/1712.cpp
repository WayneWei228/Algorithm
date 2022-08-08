#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[80];



struct Solution {
    vector<vector<int>> S;
    vector<bool> visited;
    int ans1 = 1;

    void dfs(int i) { // int dfs(int i, int total)
        if (visited[i]) return;
        visited[i] = true;
        for (int j : S[i]) {
            if (!visited[j]) {
                ans1++;
                dfs(j);
            }
        }
        return;
    }



    void Solve() {
        S.resize(2000);
        visited.resize(2000);
        int d;
        while (scanf("%d <-> ", &d) == 1) {
            while (true) {
                int nchars = -1;
                int near;
                scanf("%d, %n", &near, &nchars);
                S[d].emplace_back(near);
                if (nchars == -1) break;
            }
        }
        int ans2 = 0;
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                dfs(i);
                ans2++;
            }
            if (i == 0) {
                printf("%d\n", ans1);
            }
        }
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}