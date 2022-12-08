#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct Solution {
    ll K, M, N;
    vector<int> p;
    vector<ll> t;
    vector<int> f;
    vector<ll> b;
    vector<vector<pair<ll, ll>>> a;
    void Solve() {
        cin >> K >> M >> N;
        p.resize(K);
        t.resize(K);
        f.resize(M);
        for (int i = 0; i < K; i++) {
            cin >> p[i] >> t[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> f[i];
        }
        sort(f.begin(), f.end());
        b.resize(2);
        a.resize(200020);
        for (int i = 0; i < K; i++) {
            if (p[i] < f[0]) {
                b[0] += t[i];
            } else if (p[i] > f[M - 1]) {
                b[1] += t[i];
            } else {
                int j =
                    lower_bound(f.begin(), f.end(), p[i]) - f.begin();
                a[j].emplace_back(make_pair(p[i], t[i]));
            }
        }
        for (int j = 1; j < M; j++) {
            sort(a[j].begin(), a[j].end());
            ll l = (f[j] - f[j - 1] + 1) / 2;
            ll r = 0;
            ll s = 0;
            ll t = 0;
            for (int i = 0, i2 = 0; i < a[j].size(); i++) {
                s += a[j][i].second;
                t += a[j][i].second;
                while (a[j][i].first - a[j][i2].first >= l) {
                    s -= a[j][i2++].second;
                }
                r = max(r, s);
            }
            b.emplace_back(r);
            b.emplace_back(t - r);
        }
        ll ans = 0;
        sort(b.begin(), b.end(), greater<ll>());
        for (int i = 0; i < N && i < b.size(); i++) {
            ans += b[i];
        }
        cout << ans << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
}