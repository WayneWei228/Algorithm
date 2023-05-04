#include <cstdio>
#include <iostream>
using namespace std;

struct Solution {
    int N;
    int ans = 0;
    void Solve() {
        cin >> N;
        for (int i = 0; i < N; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            ans += ((a + b + c) >> 1);
        }
        cout << ans << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
}