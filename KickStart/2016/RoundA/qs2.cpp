#include <cstdio>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

int DX[4]{1, 0, -1, 0}, DY[4]{0, 1, 0, -1};

struct Node {
    int x, y;
};

struct Solution {
    int R, C;
    vector<vector<int>> W;
    vector<vector<int>> input;
    void Solve(int caseNo) {
        scanf("%d%d", &R, &C);
        W.resize(R + 2);
        for (auto& i : W) {
            i.resize(C + 2);
        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                scanf("%d", &W[i][j]);
            }
        }
        input = W;
    Label:
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                int around;
                vector<Node> ans;
                if (CanFlow(i, j, ans, around)) {
                    // for (auto i : W) {
                    //     for (auto j : i) {
                    //         printf("%d ", j);
                    //     }
                    //     printf("\n");
                    // }
                    for (auto k : ans) {
                        // printf(" %d %d %d\n", k.x, k.y, W[k.x][k.y]);
                        W[k.x][k.y] = around;
                    }
                    goto Label;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                ans += W[i][j] - input[i][j];
            }
        }
        printf("Case #%d: %d\n", caseNo, ans);
    }

    bool CanFlow(int i, int j, vector<Node>& answer, int& around) {
        vector<vector<bool>> Visited;
        Visited.resize(R + 2);
        for (auto& i : Visited) {
            i.resize(C + 2);
        }
        around = numeric_limits<int>::max();
        queue<Node> nodes;
        nodes.emplace(Node{i, j});
        answer.emplace_back(Node{i, j});
        while (!nodes.empty()) {
            auto front = nodes.front();
            if (W[front.x][front.y] == 0) return false;
            nodes.pop();
            for (int i = 0; i < 4; i++) {
                int xnew = front.x + DX[i];
                if (xnew < 0 || xnew > R + 1) continue;
                int ynew = front.y + DY[i];
                if (ynew < 0 || ynew > C + 1) continue;
                if (Visited[xnew][ynew]) continue;
                if (W[xnew][ynew] <= W[front.x][front.y]) {
                    nodes.emplace(Node{xnew, ynew});
                    if (xnew > 0 && xnew < R + 1 && ynew > 0 &&
                        ynew < C + 1) {
                        answer.emplace_back(Node{xnew, ynew});
                    }
                    Visited[xnew][ynew] = true;
                } else {
                    if (W[xnew][ynew] < around) {
                        around = W[xnew][ynew];
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}