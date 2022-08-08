#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long int64;

struct Solution {
    int N, K;
    vector<int64> v[4];
    unordered_map<int64, int> u1;
    unordered_map<int64, int> u2;
    int64 ans = 0;
    void Solve(int caseNo) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < N; j++) {
                int d;
                scanf("%d", &d);
                v[i].emplace_back(d);
            }
        }
        for (int i = 0; i < v[0].size(); i++) {
            for (int j = 0; j < v[1].size(); j++) {
                int64 d = (v[0][i] ^ v[1][j]);
                u1[d]++;
            }
        }
        v[0].clear();
        v[1].clear();
        for (auto i : u1) {
            for (int j = 0; j < v[2].size(); j++) {
                int64 d = (i.first ^ v[2][j]);
                u2[d] += i.second;
            }
        }
        v[2].clear();
        swap(u1, u2);
        u2.clear();
        for (auto i : u1) {
            for (int j = 0; j < v[3].size(); j++) {
                if ((i.first ^ v[3][j]) == K) {
                    ans += i.second;
                }
            }
        }
        printf("Case #%d: %lld\n", caseNo, ans);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}