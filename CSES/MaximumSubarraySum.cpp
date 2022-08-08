#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
/*
8
-1 3 -2 5 3 -5 2 2
*/

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll a = 0;
    ll b = arr[0];
    for(ll i = 0; i < n; i++) {
        a = max(arr[i], a + arr[i]);
        b = max(b, a);
    }
    cout << b << '\n';
}



// int main() { 
//     ll n;
//     cin >> n;
//     ll a = 0, b = -inf, cur = 0;
//     for(int i = 0; i < n; i++) {
        
//     }
// }