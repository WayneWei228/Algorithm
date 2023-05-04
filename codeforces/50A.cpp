#include <cstdio>
#include <iostream>
using namespace std;

struct Solution {
    int M, N;
    int ans;
    void Solve() {
        cin >> M >> N;
        if (M % 2 == 0 || N % 2 == 0) {
            ans = M * N / 2;
        } else {
            ans = (M - 1) * N / 2 + (N - 1) / 2;
        }
        cout << ans << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
} 