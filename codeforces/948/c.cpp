/**
 *    author:  tourist
 *    created: 26.05.2024 10:37:38
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> divs;
        for (int x = 1; x * x <= a.back(); x++) {
            if (a.back() % x == 0) {
                divs.push_back(x);
                divs.push_back(a.back() / x);
            }
        }
        sort(divs.begin(), divs.end());
        divs.resize(unique(divs.begin(), divs.end()) - divs.begin());

        for (auto i : a) {
            cout << i << " ";
        }
        cout << endl;

        for (auto i : divs) {
            cout << i << " ";
        }
        cout << endl;
        int sz = int(divs.size());

        auto Find = [&](int x) {
            auto it = lower_bound(divs.begin(), divs.end(), x);
            if (it == divs.end() || *it != x) {
                return -1;
            }
            return int(it - divs.begin());
        };

        bool full = false;
        for (int i = 0; i < n; i++) {
            if (Find(a[i]) == -1) {
                full = true;
                break;
            }
        }

        if (full) {
            cout << n << '\n';
            continue;
        }
        const int inf = int(1e9);
        vector<int> dp(sz, -inf);
        dp[0] = 0;
        for (int num : a) {
            for (int i = sz - 1; i >= 0; i--) {
                int u = divs[i] / __gcd(divs[i], num) * num;
                int id = Find(u);
                assert(id != -1);
                dp[id] = max(dp[id], dp[i] + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            if (find(a.begin(), a.end(), divs[i]) == a.end()) {
                ans = max(ans, dp[i]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}