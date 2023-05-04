#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Solution {
    int N, K;
    int ans = 0;
    vector<int> arr;
    void Solve() {
        cin >> N >> K;
        arr.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < N; i++) {
            if (arr[i] != 0 && arr[i] >= arr[K - 1]) {
                ans++;
            }
        }
        cout << ans << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
}