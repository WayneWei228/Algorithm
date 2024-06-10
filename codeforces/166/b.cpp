#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n + 1; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        int target = b[n];
        long long total = 0;
        bool justcopy = false;
        int closed = 1e9 + 10;
        for (int i = 0; i < n; i++) {
            total += abs(a[i] - b[i]);
            if ((a[i] <= target && target <= b[i]) ||
                (b[i] <= target && target <= a[i])) {
                justcopy = true;
            } else {
                closed = min(closed, min(abs(a[i] - target),
                                         abs(b[i] - target)));
            }
        }
        if (justcopy) {
            total += 1;
        } else {
            total += closed + 1;
        }
        cout << total << endl;
    }
    return 0;
}