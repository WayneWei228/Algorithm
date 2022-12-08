#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct Solution {
    int N, M;
    int f[100050];
    int g[100050];
    int h[100050];
    vector<int> a, b;

    int Q(const vector<int>& a, int x) {
        int j = lower_bound(a.begin(), a.end(), x) - a.begin();
        int mn = N;
        if (j < a.size()) {
            mn = min(mn, a[j] - x);
        }
        if (0 < j) {
            mn = min(mn, x - a[j - 1]);
        }
        return mn;
    }

    int F(int x) { return f[x] != x ? f[x] = F(f[x]) : x; }

    void U(int x, int y) {
        x = F(x);
        y = F(y);
        f[x] = y;
    }

    void Solve() {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            f[i] = i;
            g[i] = N;
            h[i] = N;
        }
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            U(x, y);
        }
        if (f[1] == f[N]) {
            cout << 0 << endl;
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (F(i) == F(1)) {
                a.emplace_back(i);
            }
            if (F(i) == F(N)) {
                b.emplace_back(i);
            }
        }
        for (int i = 1; i <= N; i++) {
            int fi = F(i);
            g[fi] = min(g[fi], Q(a, i));
            h[fi] = min(h[fi], Q(b, i));
        }
        ll z = (ll)N * N;
        for (int i = 1; i <= N; i++) {
            z = min(z, (ll)g[i] * g[i] + (ll)h[i] * h[i]);
        }
        cout << z << endl;
    }
};

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        Solution().Solve();
    }
    return 0;
}