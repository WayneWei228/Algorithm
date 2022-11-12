#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long int64;

struct Solution {
    int64 x, y;
    void Solve() {
        cin >> x >> y;
        int64 z = 1e18;
        int64 c = 0;
        while (true) {
            if (x > y) {
                if (x % 2 == 1) {
                    x++;
                    c++;
                }
                x /= 2;
                c++;
            } else {
                z = min(z, c + y - x);
                if (x == y) break;
                if (y % 2 == 1) {
                    --y;
                    c++;
                } else {
                    y /= 2;
                    c++;
                }
            }
        }
        cout << z << endl;
    }
};

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        Solution().Solve();
    }
    return 0;
}