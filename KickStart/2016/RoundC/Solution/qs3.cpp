#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

char Buffer[80];

// DFS 有连到祖先的边（环）就是不可能
/*
首先找到一个没有人指向它的节点为起点
把这个点从图中删除
把这个点所有出去的边也删除
此时重复执行12行
最终的拓扑排序就是删除所有点的顺序
如果某一时刻找不到没有人指向它的节点
说明这个图不可能

拓扑排序：
有依赖关系求先后顺序

已知偏序求全序
偏序：两两之间的顺序
全序：总排序
*/
struct Solution {
    int N;
    unordered_map<string, int> ToNumber;
    vector<vector<int>> Out;
    vector<int> Visited;

    int MapToNumber(const string& s) {
        return ToNumber.emplace(s, ToNumber.size()).first->second;
    }

    void Solve(int caseNo) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf(" %[^=]=%*[^(](", Buffer);
            int v = MapToNumber(Buffer);
            if (Out.size() <= v) Out.resize(v + 1);
            while (true) {
                scanf(",");
                if (scanf("%[^,)]", Buffer) == 0) break;
                int v0 = MapToNumber(Buffer);
                if (Out.size() <= v0) Out.resize(v0 + 1);
                Out[v0].emplace_back(v);
            }
            scanf(")");
        }
        printf("Case #%d: %s\n", caseNo, Topo() ? "GOOD" : "BAD");
    }

    bool Topo() {
        if (Out.size() != N) return false;
        Visited.resize(N);
        for (int i = 0; i < N; ++i) {
            if (Visited[i] == 0 && !VisitOK(i)) return false;
        }
        return true;
    }

    bool VisitOK(int no) {
        Visited[no] = 1; // 开始访问
        for (int i : Out[no]) {
            if (Visited[i] == 1) return false; 
            if (Visited[i] == 0 && !VisitOK(i)) return false;
        }
        Visited[no] = 2; // 访问完
        return true;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}