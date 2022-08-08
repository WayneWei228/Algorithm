/*
ID: waynewei
PROB: gift1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    vector<string> arr;
    map<string,int> mp;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string a;
        cin >> a;
        arr.push_back(a);
        mp[a] = 0;
    }
    for(int i = 0; i < n; i++) {
        string a;
        int l, r;
        cin >> a >> l >> r;
        if(r == 0) {
            mp[a] += l;
            continue;
        }
        int give = l / r;
        for(int i = 0; i < r; i++) {
            string b;
            cin >> b;
            mp[b] += give;
        }
        mp[a] -= give * r;
    }
    for(auto e : arr) {
        cout << e << " " << mp[e] << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}