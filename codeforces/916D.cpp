#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> largest_three(const vector<int>& num) {
    int mx1 = -1, mx2 = -1, mx3 = -1; 
    for (int j = 0; j < num.size(); j++) {
        if (mx1 == -1 || num[j] > num[mx1]) { // mx is index, so we can't write num[j] > mx 
            mx3 = mx2;
            mx2 = mx1;
            mx1 = j;
        } else if (mx2 == -1 || num[j] > num[mx2]) {
            mx3 = mx2;
            mx2 = j;
        } else if (mx3 == -1 || num[j] > num[mx3]) {
            mx3 = j;
        }
    }
    return {mx1, mx2, mx3};
}

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    // cout << "----" << endl;
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "-----" << endl;

    int mx = -1;
    for (const auto& i : largest_three(a)) {
        for (const auto& j : largest_three(b)) {
            for (const auto& k : largest_three(c)) {
                if (i != j && i != k && j != k) {
                    mx = max(mx, a[i] + b[j] + c[k]);
                }
            }
        }
    }
    cout << mx << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        Solve();
    }
}