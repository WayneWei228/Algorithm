#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Solution {
    int N;
    vector<vector<int>> r;
    vector<int> a;
    void Solve() {
        scanf("%d", &N);
        r.resize(N + 1);
        for (auto& i : r) {
            i.resize(N + 1);
        }
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                scanf("%d", &r[i][j]);
            }
        }

        a.resize(N);
        a[1] = 0;
        a[2] = r[1][2];
        int sign = 1;
        int i = 2;
        for (int j = 3; j <= N; j++) {
            if (r[i - 1][j] == r[i - 1][i] + r[i][j]) {
                a[j] = a[j - 1] + sign * r[i][j];
            } else {
                sign *= -1;
                a[j] = a[j - 1] + sign * r[i][j];
            }
            if (r[j - 1][j] > 0) {
                i = j;
            }
        }

        bool head = true;
        for (int i = 1; i <= N; i++) {
            if (head) {
                printf("%d", a[i]);
                head = false;
            } else {
                printf(" %d", a[i]);
            }
        }
        printf("\n");
    }
};

int main() {
    Solution().Solve();
    return 0;
}