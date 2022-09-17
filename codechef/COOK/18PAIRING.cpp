#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Edge {
    int f, t;
};

struct Solution {
    int N, M;
    vector<Edge> Edges;
    vector<char> P;  // 边
    vector<int> Answer;
    void Solve() {
        scanf("%d%d", &N, &M);
        Edges.resize(M);
        for (int i = 0; i < M; i++) {
            scanf("%d%d", &Edges[i].f, &Edges[i].t);
        }
        P.resize(N);
        for (int i = M - 1; i >= 0; i--) {
            if (P[Edges[i].f] || P[Edges[i].t]) continue;
            P[Edges[i].f] = P[Edges[i].t] = true;
            Answer.emplace_back(i);
        }
        bool head = true;
        for (int i = Answer.size() - 1; i >= 0; i--) {
            if (!head) {
                printf(" ");
            }
            head = false;
            printf("%d", Answer[i]);
        }
        printf("\n");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}