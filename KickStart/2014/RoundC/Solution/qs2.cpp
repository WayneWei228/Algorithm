#include <cstdio>
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Vertex {
    int Line, Station;
    bool OnTrain;

    bool operator==(const Vertex& that) const {
        return Line == that.Line && Station == that.Station &&
               OnTrain == that.OnTrain;
    }
};

struct VertexHash {
    size_t operator()(const Vertex& v) const {
        size_t answer = v.Line;
        answer = answer * 9875321 + v.Station;
        answer = answer * 9875321 + v.OnTrain;
        return answer;
    }
};

struct Edge {
    int To, Cost;
};

struct Node {
    int No, Distance;

    bool operator<(const Node& that) const {
        return that.Distance < Distance;
    }
};

struct Solution {
    int N, M, Q;
    unordered_map<Vertex, int, VertexHash> ToNumber;
    /*
    把每个点 To 哪些的点具体写下来可能会爆内存
    然而 像 二维地图 我们知道指定点 当即用Near来寻找 To点 会占用更小内存
    */
    vector<vector<Edge>> Out;
    vector<int> W;

    void Solve(int caseNo) {
        scanf("%d", &N);
        W.resize(N);
        auto mapToNumber = [this](const Vertex& v) {  // 三维压一维
            int r = ToNumber.emplace(v, ToNumber.size()).first->second;
            if (Out.size() <= r) Out.resize(r + 1);
            return r;
        };
        for (int i = 0; i < N; ++i) {
            int sn;
            scanf("%d%d", &sn, &W[i]);
            for (int j = 1; j < sn; ++j) {
                int time;
                scanf("%d", &time);
                int v0 = mapToNumber(Vertex{i, j - 1, true});
                int v1 = mapToNumber(Vertex{i, j, true});
                Out[v0].emplace_back(Edge{v1, time});
                Out[v1].emplace_back(Edge{v0, time});
            }
        }
        scanf("%d", &M);
        for (int i = 0; i < M; ++i) {
            int m0, s0, m1, s1, time;
            scanf("%d%d%d%d%d", &m0, &s0, &m1, &s1, &time);
            int v0 = mapToNumber(Vertex{m0 - 1, s0 - 1, true});
            int v1 = mapToNumber(Vertex{m0 - 1, s0 - 1, false});
            int v2 = mapToNumber(Vertex{m1 - 1, s1 - 1, false});
            int v3 = mapToNumber(Vertex{m1 - 1, s1 - 1, true});
            // 所有管道可上下车
            Out[v0].emplace_back(Edge{v1, 0});  // 起点车上 到 起点车下
            Out[v1].emplace_back(
                Edge{v0, W[m0 - 1]});  // 起点车下 到 起点车上
            Out[v1].emplace_back(Edge{v2, time});
            Out[v2].emplace_back(Edge{v1, time});
            Out[v2].emplace_back(Edge{v3, W[m1 - 1]});
            Out[v3].emplace_back(Edge{v2, 0});
        }
        scanf("%d", &Q);
        printf("Case #%d:\n", caseNo);
        for (int i = 0; i < Q; ++i) {
            int m0, s0, m1, s1;
            scanf("%d%d%d%d", &m0, &s0, &m1, &s1);
            // 考虑起点终点上下车
            int v0 = mapToNumber(Vertex{m0 - 1, s0 - 1, false});
            int v1 = mapToNumber(Vertex{m1 - 1, s1 - 1, false});
            int v2 = mapToNumber(Vertex{m0 - 1, s0 - 1, true});
            int v3 = mapToNumber(Vertex{m1 - 1, s1 - 1, true});
            Out[v0].emplace_back(Edge{v2, W[m0 - 1]});
            Out[v2].emplace_back(Edge{v0, 0});
            Out[v1].emplace_back(Edge{v3, W[m1 - 1]});
            Out[v3].emplace_back(Edge{v1, 0});
            printf("%d\n", Dijkstra(v0, v1));
        }
        //其实可将所有点自身点车上连到车下
    }

    int Dijkstra(int begin, int end) {
        priority_queue<Node> nodes;
        vector<int> distance(Out.size(), numeric_limits<int>::max());
        distance[begin] = 0;
        nodes.emplace(Node{begin, 0});
        while (!nodes.empty()) {
            Node top = nodes.top();
            nodes.pop();
            if (distance[top.No] < top.Distance) continue;
            if (top.No == end) return top.Distance;
            for (const Edge& i : Out[top.No]) {
                int newDistance = top.Distance + i.Cost;
                if (newDistance < distance[i.To]) {
                    distance[i.To] = newDistance;
                    nodes.emplace(Node{i.To, newDistance});
                }
            }
        }
        return -1;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}