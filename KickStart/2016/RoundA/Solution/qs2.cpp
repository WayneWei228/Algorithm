#include <cstdio>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

int DX[4]{1, 0, -1, 0}, DY[4]{0, 1, 0, -1};
/*
https://leetcode-cn.com/problems/trapping-rain-water-ii/solution/gong-shui-san-xie-jing-dian-dijkstra-yun-13ik/
1. 从点 (x, y) 到边界的所有路径高度的最小值为多少
此点到边界所有路径高度会把这点包围住
2. 这个路径高度的最小值与 (x, y) 本身的高度 heightMap[x][y]
之间的差值，即是该点能接到的雨水数量。
3. 「从 (x, y)出发到达边界的路径」也可看作「从边界到达点 (x, y) 的路径」
4. 使用超级源点进行简化：超级源点与所有的边界格子连有一条权值为 0
的边，从而进一步将问题转化为「求从超级源点出发到达 (x, y)
的路径高度的最小值」
5. 使用出队元素更新相邻格子的雨水量
6.如果我们能够保证被出队元素所更新的高度为最终高度
（或者说出队元素的高度为最终高度），那么该做法的正确性就能被
Dijkstra 的正确性所保证。
7. 对于某个位置 (x, y) 而言，根据「木桶原理」，
其最终高度取决于四个方向的邻点的最终高度的最小值。
*/
struct Node {
    int X, Y, Distance;

    bool operator<(const Node& that) const {
        return Distance < that.Distance;
    }
};

struct Solution {
    int R, C;
    vector<vector<int>> H, Distance;

    void Solve(int caseNo) {
        scanf("%d%d", &R, &C);
        H.resize(R);
        for (auto& i : H) {
            i.resize(C);
            for (auto& j : i) scanf("%d", &j);
        }
        Dijkstra();
        int answer = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                answer += Distance[i][j] - H[i][j];
            }
        }
        printf("Case #%d: %d\n", caseNo, answer);
    }

    void Dijkstra() {
        Distance.resize(R);
        for (auto& i : Distance) {
            i.resize(C, numeric_limits<int>::max());
        }
        priority_queue<Node> nodes;
        auto add = [&](int x, int y) {
            Distance[x][y] = H[x][y];
            nodes.emplace(Node{x, y, Distance[x][y]});
        };
        // 加入四周边界
        for (int i = 0; i < C; ++i) add(0, i), add(R - 1, i);
        for (int i = 0; i < R; ++i) add(i, 0), add(i, C - 1);
        while (!nodes.empty()) {
            Node n = nodes.top();
            nodes.pop();
            if (Distance[n.X][n.Y] < n.Distance) continue;
            for (int i = 0; i < 4; ++i) {
                int newX = n.X + DX[i], newY = n.Y + DY[i];
                if (newX < 0 || R <= newX) continue;
                if (newY < 0 || C <= newY) continue;
                int newDistance = max(n.Distance, H[newX][newY]);
                if (newDistance < Distance[newX][newY]) {
                    Distance[newX][newY] = newDistance;
                    nodes.emplace(Node{newX, newY, newDistance});
                }
            }
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}