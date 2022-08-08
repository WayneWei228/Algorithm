#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Soldier {
    int A[2];
};

struct Solution {
    int N;
    vector<Soldier> S;

    void Solve(int caseNo) {
        scanf("%d", &N);
        S.resize(N);
        for (Soldier& i : S) scanf("%d%d", &i.A[0], &i.A[1]);
        for (int i = 0; i < 2; ++i) Discretize(i);
        vector<vector<char>> w(N + 1), e[3], s[3];
        for (auto& i : w) i.resize(N + 1);
        for (int i = 0; i < 3; ++i) {
            e[i].resize(N + 1);
            for (auto& j : e[i]) j.resize(N + 1);
            s[i].resize(N + 1);
            for (auto& j : s[i]) j.resize(N + 1);
            for (const Soldier& j : S) s[i][j.A[0]][j.A[1]] = true;
        }
        for (int i = 0; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s[0][i][j - 1]) s[0][i][j] = true;
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (s[1][i - 1][j]) s[1][i][j] = true;
            }
        }
        for (int i = N; i >= 0; --i) {
            for (int j = N; j >= 0; --j) {
                if (i + 1 <= N) {
                    e[0][i][j] = e[0][i + 1][j] ||  //
                                 (s[0][i + 1][j] && !w[i + 1][j]);
                } 
                // s[0] 表示 某个点的左边有没有 soilder
                // soilder 的前缀或
                if (j + 1 <= N) {
                    e[1][i][j] = e[1][i][j + 1] ||  //
                                 (s[1][i][j + 1] && !w[i][j + 1]);
                }
                if (i + 1 <= N && j + 1 <= N) {
                    e[2][i][j] =
                        e[2][i + 1][j] || e[2][i][j + 1] ||
                        (s[2][i + 1][j + 1] && !w[i + 1][j + 1]);
                }
                w[i][j] = e[0][i][j] || e[1][i][j] || e[2][i][j];
            }
        }
        printf("Case #%d: %s\n", caseNo, w[0][0] ? "YES" : "NO");
    }

    void Discretize(int dim) {
        vector<int> v{0};
        for (const Soldier& i : S) v.emplace_back(i.A[dim]);
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        for (Soldier& i : S) {
            i.A[dim] =
                lower_bound(v.begin(), v.end(), i.A[dim]) - v.begin();
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}