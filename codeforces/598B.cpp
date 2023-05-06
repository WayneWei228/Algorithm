#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;

/*
abcde
eabcd
deabc
cdeab

abc
cab
bca
abc
*/
struct Solution {
    void Solve() {
        int l, r, k;
        cin >> l >> r >> k;
        int len = r - l + 1;
        int cut = k % len;
        s = s.substr(0, l - 1) + s.substr(r - cut, cut) +
            s.substr(l - 1, len - cut) + s.substr(r);
    }
};

int main() {
    cin >> s;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        Solution().Solve();
    }
    cout << s << endl;
    return 0;
}