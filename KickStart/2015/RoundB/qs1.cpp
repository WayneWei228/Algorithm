#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int To;
    vector<int> Dis;
};

struct Node {
    int No, Time, Distance;

    bool operator<(const Node& that) const {
        return Distance < that.Distance;
    }
};

struct Solution {
    int N, M, K;
    vector<vector<Edge>> Out;
    void Solve(int caseNo) {
        scanf("%d%d%d", &N, &M, &K);
        Out.resize(N);
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--, b--;
            if (Out[a].size() <= b) Out[a].resize(b + 1);
            if (Out[b].size() <= a) Out[b].resize(a + 1);
            Out[a][b].To = b;
            Out[b][a].To = a;
            Edge& e1 = Out[a][b];
            Edge& e2 = Out[b][a];
            e1.Dis.resize(24);
            e2.Dis.resize(24);
            for (int j = 0; j < 24; j++) {
                int t;
                scanf("%d", &t);
                e1.Dis[j] = t;
                e2.Dis[j] = t;
            }
        }
        printf("Case #%d:", caseNo);
        for (int i = 0; i < K; i++) {
            int end, time;
            scanf("%d%d", &end, &time);
            end--;
            int ans = Dijkstra(0, end, time);
            printf(" %d", ans);
        }
        printf("\n");
    }

    int Dijkstra(int begin, int end, int time) {
        priority_queue<Node> nodes;
        vector<vector<int>> distance (N);
        for (int i = 0; i < distance.size(); i++) {
            distance[i].resize(24, numeric_limits<int>::max());
        }
        distance[begin][time] = 0;
        nodes.emplace(Node{0, time, 0});
        while (!nodes.empty()) {
            Node top = nodes.top();
            nodes.pop();
            if (distance[top.No][top.Time] < top.Distance) continue;
            for (const Edge& i : Out[top.No]) {
                int newDistance = top.Distance + i.Dis[(top.Time) % 24];
                int newTime = (top.Time + i.Dis[(top.Time) % 24]) % 24;
                if (newDistance < distance[i.To][newTime]) {
                    distance[i.To][newTime] = newDistance;
                    nodes.emplace(Node{i.To, newTime, newDistance});
                }
            } 
        }
        int ans = *min_element(distance[end].begin(), distance[end].end());
        if (ans == numeric_limits<int>::max()) {
            return -1;
        } else {
            return ans;
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}