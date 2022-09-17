#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

/* 
此代码忽略了 2^i 特性
特性: 从大到小，如果可选就选，因为当前的值等于之后所有小值之和
尝试了回溯算法, 超时
*/

struct Edge {
    int f, t, v;

    bool operator<(const Edge& that) const { return v > that.v; }
};

struct Solution {
    int N, M, Answer = 0;
    vector<Edge> Edges;
    vector<int> indices;  // 边下标
    vector<bool> chosen;  // 节点
    vector<bool> p;       // 边
    void Solve() {
        scanf("%d%d", &N, &M);
        Edges.resize(M);
        for (int i = 0; i < M; i++) {
            scanf("%d%d", &Edges[i].f, &Edges[i].t);
            Edges[i].v = pow(2, i);
        }
        // sort(Edges.begin(), Edges.end());
        chosen.resize(N);
        p.resize(M);
        bool head = true;
        Compute(0, 0);
        for (int i = 0; i < indices.size(); i++) {
            if (!head) {
                printf(" ");
                head = false;
            }
            printf(" %d", indices[i]);
        }
        printf("\n");
    }

    void Compute(int no, int value) {
        if (no == M) {
            if (value >= Answer) {
                Answer = value;
                indices.clear();
                for (int i = 0; i < p.size(); i++) {
                    if (p[i]) {
                        indices.emplace_back(i);
                    }
                }
            }
            return;
        }
        if (chosen[Edges[no].f] ||
            chosen[Edges[no].t]) {  // 如果左右选了，跳过
            return Compute(no + 1, value);
        }

        chosen[Edges[no].f] = true;
        chosen[Edges[no].t] = true;
        p[no] = true;
        Compute(no + 1, value + Edges[no].v);  // 选这个
        p[no] = false;
        chosen[Edges[no].f] = false;
        chosen[Edges[no].t] = false;
        Compute(no + 1, value);  // 不选这个
        return;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}