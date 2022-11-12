#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int64;

struct Solution {
    int N;
    vector<pair<int64, int64>> a, b;
    pair<int64, int64> c[1048577];
    vector<pair<int64, int64>> A[42], B[42];

    void gen(vector<pair<int64, int64>> &a,
             vector<pair<int64, int64>> A[]) {
        // for (auto& i : c) {
        //     i.first = i.second = 0;
        // }
        memset(c, 0, sizeof c);
        for (int i = 0; i < a.size(); i++) {
            c[1 << i] = a[i];
        }
        for (int i = 1; i < 1 << a.size(); i++) {
            int lb = i & -i;
            int j = i - lb;
            c[i] = make_pair(c[lb].first + c[j].first,
                             c[lb].second + c[j].second);
        }
        for (int i = 0; i < 1 << a.size(); i++) {
            A[__builtin_popcount(i)].emplace_back(c[i]);
        }
        return;
    }

    void Solve() {
        cin >> N;
        pair<int64, int64> goal;
        cin >> goal.first >> goal.second;
        for (int i = 0; i < N; i++) {
            pair<int64, int64> p;
            cin >> p.first >> p.second;
            if (i & 1) {
                a.emplace_back(p);
            } else {
                b.emplace_back(p);
            }
        }
        gen(a, A);
        gen(b, B);
        for (int i = 0; i <= N; i++) {
            sort(A[i].begin(), A[i].end());
            sort(B[i].begin(), B[i].end());
        }
        for (int k = 1; k <= N; k++) {
            int64 ans = 0;
            for (int i = 0; i <= k; i++) {
                for (auto p : A[i]) {
                    int left = k - i;
                    auto need = make_pair(goal.first - p.first,
                                          goal.second - p.second);
                    ans += upper_bound(B[left].begin(), B[left].end(),
                                       need) -
                           lower_bound(B[left].begin(), B[left].end(),
                                       need);
                }
            }
            cout << ans << endl;
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}