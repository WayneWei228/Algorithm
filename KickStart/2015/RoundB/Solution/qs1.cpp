#include <cstdio>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

/*
一点拆成无限多个点
start: i x
(i, x) -> (j, x + Cost[x % 24]);

(k, n) find minimum n when (i, x) can reach (k, n)


Cost[t] ≤ Cost[t+1]+1


拆成24问题
0点出发原点开始何时最早到

*/

struct Edge {
    int SumV, Cost[24];
};

struct Node {
    int No, Distance;

    bool operator<(const Node& that) const {
        return that.Distance < Distance;
    }
};

struct Solution {
    int N, M, K;
    vector<Edge> E;
    vector<vector<int>> Out;
    vector<int> Distance[24];

    void Solve(int caseNo) {
        scanf("%d%d%d", &N, &M, &K);
        Out.resize(N);
        for (int i = 0; i < M; ++i) {
            int v0, v1;
            scanf("%d%d", &v0, &v1);
            --v0;
            --v1;
            E.emplace_back();
            E.back().SumV = v0 + v1;
            for (int j = 0; j < 24; ++j) scanf("%d", &E.back().Cost[j]);
            // 适用于无向图存复杂信息，Cost 存一遍就行
            // 放的是边的序号
            // 好处在于边只存一遍，不需来回存
            Out[v0].emplace_back(E.size() - 1);
            Out[v1].emplace_back(E.size() - 1);
        }
        for (int i = 0; i < 24; ++i) Dijkstra(i);
        printf("Case #%d:", caseNo);
        for (int i = 0; i < K; ++i) {
            int d, s;
            scanf("%d%d", &d, &s);
            int answer = Distance[s][d - 1];
            if (answer == numeric_limits<int>::max()) answer = -1;
            printf(" %d", answer);
        }
        printf("\n");
    }

    void Dijkstra(int startTime) {
        auto& distance = Distance[startTime];
        priority_queue<Node> nodes;
        distance.resize(Out.size(), numeric_limits<int>::max());
        distance[0] = 0;
        nodes.emplace(Node{0, 0});
        while (!nodes.empty()) {
            Node top = nodes.top();
            nodes.pop();
            if (distance[top.No] < top.Distance) continue;
            for (int i : Out[top.No]) {
                int to = E[i].SumV - top.No;
                int cost = E[i].Cost[(startTime + top.Distance) % 24];
                int newDistance = top.Distance + cost;
                if (newDistance < distance[to]) {
                    distance[to] = newDistance;
                    nodes.emplace(Node{to, newDistance});
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
