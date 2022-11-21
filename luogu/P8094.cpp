#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;

struct Solution {
    int N;
    stack<pair<ll, ll>> s;
    ll ans = 0;

    void Solve() {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            pair<ll, ll> x;
            cin >> x.first;
            x.second = i;
            while (!s.empty() && x.first >= s.top().first) {
                auto u = s.top();
                s.pop();
                ans += i - u.second + 1;
            }
            if (!s.empty()) {
                ans += i - s.top().second + 1;
            }
            s.emplace(x);
        }
        cout << ans << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
} 