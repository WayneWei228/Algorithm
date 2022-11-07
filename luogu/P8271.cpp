#include <cstdio>
#include <iostream>
using namespace std;

struct Solution {
    string s;
    int N;
    void Solve() {
        cin >> s >> N;
        int a[s.size() + 1];
        for (int i = 1; i <= s.size(); i++) {
            int r;
            if (s[i - 1] == 'C') {
                r = 1;
            } else if (s[i - 1] == 'O') {
                r = 2;
            } else {
                r = 3;
            }
            a[i] = a[i - 1] ^ r;
        }
        for (int i = 0; i < N; i++) {
            int l, r;
            cin >> l >> r;
            cout << ((a[r] ^ a[l - 1]) == 1 ? 'Y' : 'N');
        }
        cout << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
} 