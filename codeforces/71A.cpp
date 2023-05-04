#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct Solution {
    int N;
    void Solve() {
        cin >> N;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            if (s.size() > 10) {
                cout << s[0] << s.size() - 2 << *(s.end() - 1) << endl;
            } else {
                cout << s << endl;
            }
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}