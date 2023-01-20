#include <cstdio>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const ll mx = 3e6 + 9;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> ans;
    for (ll i = 0; i < n; i++) {
        ll rem = n - i - 1;
        ll cur = min(k - rem, m);
        if (cur <= 0) break;
        ll val;
        if (cur > i) {
            val = min(m, i + 1);
            cur = val;
        } else
            val = ans[i - cur];
        ans.push_back(val);
        k = k - cur;
    }
    if (k == 0 && (ll)ans.size() == n) {
        for (auto x : ans) cout << x << ' ';
        cout << endl;
    } else
        cout << -1 << endl;

    vector<ll> aans;

    /*
    1 2 3 4 5 6 7 8 9 10
    0 1 2 3 4
    stillneed dcrease
    i increase

    */
}
