#include <cstdio>
#include <vector>
using namespace std;

/*
M 条边
N 个点
N 个点中找大于等于 g 个点组成的独立集即为 possible
反之则 impossible
最大独立集等同于最小点覆盖
则问题转变成能否用 N - g 个点覆盖所有边

*/

struct Edge {
    int V[2];
};

struct Solution {
    int N, M, G;
    vector<Edge> E;
    vector<bool> Covered;

    bool Put(int no) {
        if (no == M) return true;
        if (Covered[E[no].V[0]] || Covered[E[no].V[1]]) {
            return Put(no + 1);
        }
        if (G == 0) return false;
        G--;
        for (int i = 0; i < 2; i++) {
            Covered[E[no].V[i]] = true;
            if (Put(no + 1)) return true;
            Covered[E[no].V[i]] = false;
        }
        G++;
        return false;
    }

    void Solve() {
        scanf("%d%d%d", &N, &M, &G);
        E.resize(M);
        for (int i = 0; i < M; i++) {
            scanf("%d%d", &E[i].V[0], &E[i].V[1]);
        }
        Covered.resize(N);
        G = N - G;
        if (Put(0)) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}  