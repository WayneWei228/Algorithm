#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using vl = vector<ll>;
// 前缀和数组要多开一个
int main() {
    int N, Q;
    cin >> N >> Q;
    vl arr(N);
    for(ll &x: arr) {
        cin >> x;
    }
    vl psum(N + 1);

    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + arr[i - 1];
    }
    // for(ll x:psum) {
    //     cout << x << " ";
    // }
    for(int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << psum[r] - psum[l] << endl;
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// #define sz(x) (int)size(x)

// using ll = long long;
// using vl = vector<ll>;

// vl psum(const vl& a) {
// 	vl psum(sz(a)+1);
// 	for (int i = 0; i < sz(a); ++i)
// 		psum[i+1] = psum[i]+a[i];
// 	// or partial_sum(begin(a),end(a),begin(psum)+1);
// 	return psum;
// }

// int main() {
// 	int N, Q;
// 	cin >> N >> Q;
// 	vl a(N);
// 	for (ll& x: a)
// 		cin >> x;
// 	vl p = psum(a);
// 	for (int i = 0; i < Q; ++i) {
// 		int l, r;
// 		cin >> l >> r;
// 		cout << p[r] - p[l] << "\n";
// 	}
// }
