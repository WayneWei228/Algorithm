#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int T;

struct Solution {
    int N;
    vector<int> V[2];
    vector<int> Final;
    void Solve() {
        cin >> N;
        Final.resize(N);
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            if ((a & 1)) {
                V[1].emplace_back(a);
                Final[i] = 1;
            } else {
                V[0].emplace_back(a);
                Final[i] = 0;
            }
        }

        sort(V[1].begin(), V[1].end());
        sort(V[0].begin(), V[0].end(),
             [](int a, int b) { return a > b; });
        int idx0 = 0;
        int idx1 = 0;
        for (int i = 0; i < N; i++) {
            if (Final[i] == 0) {
                Final[i] = V[0][idx0++];
            } else {
                Final[i] = V[1][idx1++];
            }
        }
        for (auto i : Final) {
            cout << " " << i;
        }
        cout << endl;
    }
};

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ":";
        Solution().Solve();
    }
    return 0;
}
