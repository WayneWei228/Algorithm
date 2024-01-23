#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void Solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    int sum = 0;
    int mx = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < min(n, k); i++) {
        sum += a[i];
        mx = max(mx, b[i]);
        ans = max(ans, sum + mx * (k - i - 1));
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        Solve();
    }
    return 0;
}