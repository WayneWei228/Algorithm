#include <cstdio>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int line, stat;
    int dis;
};

struct Node {
    int line, stat;
    int Distance;
    bool metro;
    bool operator<(const Node& that) const {
        return that.Distance < Distance;
    }
};

struct Solution {
    int N, M, Q;
    vector<vector<vector<Edge>>> Out;
    vector<int> W;

    void Solve(int caseNo) {
        scanf("%d", &N);
        Out.resize(N + 1);
        W.resize(N + 1);
        for (int i = 1; i <= N; i++) {  // line
            int SN, Wi;
            scanf("%d%d", &SN, &Wi);
            W[i] = Wi;
            Out[i].resize(SN + 1);
            vector<int> time(SN - 1);
            for (auto& i : time) scanf("%d", &i);
            for (int j = 1; j < SN; j++) {  // station
                Out[i][j].emplace_back(Edge{i, j + 1, time[j - 1]});
            }
            for (int j = SN; j > 1; j--) {
                Out[i][j].emplace_back(Edge{i, j - 1, time[j - 2]});
            }
        }
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            int m1, s1, m2, s2, t;
            scanf("%d%d%d%d%d", &m1, &s1, &m2, &s2, &t);
            Out[m1][s1].emplace_back(Edge{m2, s2, t});
            Out[m2][s2].emplace_back(Edge{m1, s1, t});
        }
        scanf("%d", &Q);
        printf("Case #%d:\n", caseNo);
        for (int i = 0; i < Q; i++) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            printf("%d\n", Dijkstra(x1, y1, x2, y2));
        }
    }

    int Dijkstra(int x1, int y1, int x2, int y2) {
        vector<vector<int>> Distance(Out.size());
        for (int i = 0; i < Distance.size(); i++) {
            Distance[i].resize(Out[i].size(),
                               numeric_limits<int>::max());
        }
        priority_queue<Node> nodes;
        nodes.emplace(Node{x1, y1, 0, false});
        Distance[x1][y1] = 0;
        while (!nodes.empty()) {
            Node top = nodes.top();
            nodes.pop();
            if (Distance[top.line][top.stat] < top.Distance) continue;
            if (top.line == x2 && top.stat == y2) return top.Distance;
            for (const Edge& i : Out[top.line][top.stat]) {
                bool flag = top.metro;
                int newDistance = i.dis + top.Distance;
                if (i.line == top.line) { // 同一航线
                    if (!flag) { // 之前没坐车
                        newDistance += W[i.line]; // 得等
                        flag = true; // 坐车了下次就不用等
                    }
                } else { // 不是一个航线, 意思是坐tunnel
                    flag = false; // 没坐车，下次得等
                }   
                if (Distance[i.line][i.stat] <= newDistance) continue;
                Distance[i.line][i.stat] = newDistance;
                /*
                还缺车上车下状态
                eg.  走路40，等车20，坐车 50
                如果不考虑状态，永远选择走路40，但实际上坐车更快
                */
                nodes.emplace(Node{i.line, i.stat, newDistance, flag});
            }
        }
        return -1;
    };
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}