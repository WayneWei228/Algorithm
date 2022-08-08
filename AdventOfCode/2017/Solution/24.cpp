#include <cstdio>
#include <vector>
using namespace std;

struct Edge {
    int Sum;
    bool Available = true;
};

struct Solution {
    vector<Edge> Edges;
    vector<vector<int>> Out;
    int PathStrength = 0;
    int LongPath = 0, LongPathStrength = 0;

    void Visit(int no, int length, int strength) {
        if (PathStrength < strength) PathStrength = strength;
        if (LongPath < length) {
            LongPath = length;
            LongPathStrength = strength;
        } else if (LongPath == length && LongPathStrength < strength) {
            LongPathStrength = strength;
        }
        for (int i : Out[no]) {
            Edge& e = Edges[i];
            if (!e.Available) continue;
            e.Available = false;
            Visit(e.Sum - no, length + 1, strength + e.Sum);
            e.Available = true;
        }
    }

    void Solve() {
        while (true) {
            int v0, v1;
            if (scanf("%d/%d", &v0, &v1) < 2) break;
            Edges.emplace_back(Edge{v0 + v1});
            if (Out.size() <= v0) Out.resize(v0 + 1);
            if (Out.size() <= v1) Out.resize(v1 + 1);
            // 第几个Edge
            Out[v0].emplace_back(Edges.size() - 1);
            Out[v1].emplace_back(Edges.size() - 1);
        }
        Visit(0, 0, 0);
        printf("%d\n", PathStrength);
        printf("%d\n", LongPathStrength);
    }
};

int main() {
    Solution().Solve();
    return 0;
}