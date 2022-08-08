#include <cstdio>
#include <limits>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[80];

/*
从 N 点 压缩到 n 个不同色块
因为色块相同可以无阻无限制移动

*/

struct Edge {
    int T, C;
};

struct Node {
    int No, Distance;

    bool operator<(const Node& that) const {
        return that.Distance < Distance;
    }
};

struct Solution {
    int N;
    vector<int> Color;
    vector<vector<Edge>> Out;

    void Solve(int caseNo) {
        scanf("%d", &N);
        unordered_map<string, int> toNumber;
        Color.resize(N);
        // Color[i] 是 i 所对应的 颜色序号
        
        for (int i = 0; i < N; ++i) {
            scanf("%s", Buffer);
            auto result = toNumber.emplace(Buffer, toNumber.size());
            Color[i] = result.first->second;
        }
        // 颜色数
        int colors = toNumber.size(), m, q;
        toNumber.clear();
        Out.resize(colors);
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            int v0, v1, distance;
            scanf("%d%d%d", &v0, &v1, &distance);
            v0 = Color[v0 - 1];
            v1 = Color[v1 - 1];
            Out[v0].emplace_back(Edge{v1, distance});
        }
        printf("Case #%d:\n", caseNo);
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            int source, target;
            scanf("%d%d", &source, &target);
            source = Color[source - 1];
            target = Color[target - 1];
            printf("%d\n", Dijkstra(source, target));
        }
    }

    // Dihkstra
    // 复杂度 O((n + m)log(n))

    int Dijkstra(int source, int target) {
        priority_queue<Node> nodes;
        vector<int> distance(Out.size(), numeric_limits<int>::max());
        distance[source] = 0;
        nodes.emplace(Node{source, 0});
        while (!nodes.empty()) {
            Node top = nodes.top();
            nodes.pop();

            // 以往到这里的距离比现在到这里还小 跳过
            // 允许等于dis[top.No] 进来的原因如下：
            // 这里有自己
            // 如果等于不让进，自己把自己卡掉了
            // top也是被放进去的
            // 被放的时候也更新了distance
            if (distance[top.No] < top.Distance) continue;
            if (top.No == target) return top.Distance;
            for (const Edge& i : Out[top.No]) {
                int newDistance = i.C + top.Distance;
                // 只有小于才更新，等于没必要
                if (distance[i.T] <= newDistance) continue;
                distance[i.T] = newDistance;
                nodes.emplace(Node{i.T, newDistance});
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
