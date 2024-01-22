#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Solution {
    vector<int> store[3];
    int arr[10005] = {};
    void Solve(int t) {
        for (int i = 0; i < 3; i++) {
            int n;
            cin >> n;
            store[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> store[i][j];
                arr[store[i][j]]++;
            }
        }
        for (int i = 0; i < 3; i++) {
            vector<int> replace;
            for (int j = 0; j < store[i].size(); j++) {
                if (arr[store[i][j]] == 1) {
                    replace.push_back(store[i][j]);
                }
            }
            store[i].clear();
            store[i] = replace;
        }

        int maxl = -1;
        for (int i = 0; i < 3; i++) {
            if ((int)store[i].size() > maxl) {
                maxl = (int)store[i].size();
            }
        }

        cout << "Case #" << t << ":" << endl;
        for (int i = 0; i < 3; i++) {
            if ((int)store[i].size() == maxl) {
                cout << i + 1 << " " << (int)store[i].size();
                sort(store[i].begin(), store[i].end());
                for (int j = 0; j < store[i].size(); j++) {
                    cout << " " << store[i][j];
                }
                cout << endl;
            }
        }
    }
};

int main() {
    int T;
    cin >> T;
    int t = 1;
    while (t <= T) {
        Solution().Solve(t);
        t++;
    }
}