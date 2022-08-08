#include <cstdio>
#include <limits>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int DX[4]{0, -1, 0, 1}, DY[4]{1, 0, -1, 0};

struct Coordinate {
    int X, Y;

    bool operator==(const Coordinate& that) const {
        return X == that.X && Y == that.Y;
    }
};

struct Cost {
    int Distance, Power;

    bool operator<(const Cost& that) const {
        // Distance 递增， Power 递减排序
        if (Distance != that.Distance) return Distance < that.Distance;
        return that.Power < Power;
    }
};

struct Node {
    Coordinate No;
    Cost Distance;
    // Node 的大小由 cost来决定
    bool operator<(const Node& that) const {
        return that.Distance < Distance;
    }
};

struct Solution {
    int N, M;
    Coordinate Entrance, Exit;
    vector<vector<int>> B;

    void Solve(int caseNo) {
        scanf("%d%d", &N, &M);
        scanf("%d%d%d%d", &Entrance.X, &Entrance.Y, &Exit.X, &Exit.Y);
        B.resize(N);
        for (auto& i : B) {
            i.resize(M);
            for (int& j : i) scanf("%d", &j);
        }
        printf("Case #%d: %s\n", caseNo, Dijkstra().c_str());
    }

    string Dijkstra() {
        priority_queue<Node> nodes;
        // 以 int 来表示 一个点的时候
        // distence[i] 就是答案
        // 以 X Y 表示 一个点的时候
        // distance[x][y] 就是答案

        // 二维的邻接矩阵要四维
        // map[x0][y0][x1][y1]
        
        vector<vector<Cost>> distance(N);
        for (auto& i : distance) {
            // 初始化距离为最大
            i.resize(M, {numeric_limits<int>::max()});
        }
        Cost initial{0, B[Entrance.X][Entrance.Y]};
        distance[Entrance.X][Entrance.Y] = initial;
        nodes.emplace(Node{Entrance, initial});
        while (!nodes.empty()) {
            Node top = nodes.top();
            nodes.pop();
            // top 到该点的距离比之前还要大 或者 距离跟之前一样但是power值没之前大
            // 跳过
            if (distance[top.No.X][top.No.Y] < top.Distance) continue;
            if (top.No == Exit) return to_string(top.Distance.Power);
            for (int i = 0; i < 4; i++) {
                Coordinate next{top.No.X + DX[i], top.No.Y + DY[i]};
                if (next.X < 0 || N <= next.X) continue;
                if (next.Y < 0 || M <= next.Y) continue;
                if (B[next.X][next.Y] == -1) continue;
                Cost newDistance {
                    top.Distance.Distance + 1,
                    top.Distance.Power + B[next.X][next.Y]
                };
                if (newDistance < distance[next.X][next.Y]) {
                    distance[next.X][next.Y] = newDistance;
                    nodes.emplace(Node{next, newDistance});
                }
            }
        }
        return "Mission Impossible.";
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}