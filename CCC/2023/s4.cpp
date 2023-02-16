#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u;
    int v;
    int l;
    int c;
    bool operator<(const edge& that) const {
        if (that.l != l) {
            return that.l > l;
        } else {
            return that.c > c;
        }
    }
};

struct Solution {
    int N, M;
    int ans = 0;
    vector<edge> Edges;
    int f[2005];

    int F(int x) { return f[x] != x ? f[x] = F(f[x]) : x; }

    void U(int x, int y) {
        x = F(x);
        y = F(y);
        f[x] = y;
    }

    void Solve() {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            edge x;
            cin >> x.u >> x.v >> x.l >> x.c;
            Edges.push_back(x);
        }
        sort(Edges.begin(), Edges.end());
        // cout << "Cost  Length" << endl;
        // for (int i = 0; i < M; i++) {
        //     cout << Edges[i].c << " " << Edges[i].l << endl;
        // }
        for (int i = 1; i <= N; i++) {
            f[i] = i;
        }
        for (int i = 0; i < M; i++) {
            int u = Edges[i].u;
            int v = Edges[i].v;
            int fu = F(u);
            int fv = F(v);
            if (fu != fv) {
                U(u, v);
                ans += Edges[i].c;
                // cout << "u : " << u << " v : " << v << endl;
            }
        }
        cout << ans << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
}