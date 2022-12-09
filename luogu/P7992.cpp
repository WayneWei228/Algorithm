#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

struct Solution {
    int N, M;
    ll f[100050];
    ll a[5005];
    ll b[5005];
    void Solve() {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            a[x]++;
            b[y]++;
        }
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= M; j++) {
                f[i + j] += a[i] * a[j];
                f[i + j + 1] -= b[i] * b[j];
            }
        }
        ll ans = 0;
        for (int i = 0; i <= 2 * M; i++) {
            ans += f[i];
            cout << ans << endl;
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
} 