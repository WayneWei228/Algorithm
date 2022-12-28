#include <algorithm>
#include <array>
#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N, A, B;
    vector<array<int, 3>> feature;
    vector<vector<int>> m2p, i2p;
    int ans = 0;

    void Solve() {
        scanf("%d%d%d", &N, &A, &B);
        feature.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d", &feature[i][0], &feature[i][1],
                  &feature[i][2]);
        }

        sort(feature.begin(), feature.end(),
             [&](const array<int, 3>& a, const array<int, 3>& b) {
                 return a[2] < b[2];
             });
        m2p.resize(N + 50);
        i2p.resize(N + 50);
        for (int i = 0; i < m2p.size(); i++) {
            m2p[i].resize(N + 50);
            i2p[i].resize(N + 50);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= B; j++) {
                i2p[i + 1][j] = i2p[i][j];
                if (j >= feature[i][2] * feature[i][1]) {
                    i2p[i + 1][j] =
                        max(i2p[i + 1][j],
                            i2p[i][j - feature[i][1] * feature[i][2]] +
                                feature[i][0]);
                }
            }
        }

        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j <= A; j++) {
                m2p[i][j] = m2p[i + 1][j];
                if (j >= feature[i][1]) {
                    m2p[i][j] =
                        max(m2p[i][j], m2p[i + 1][j - feature[i][1]] +
                                           feature[i][0]);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= feature[i][1]; j++) {
                if (j <= A &&
                    B - (feature[i][1] - j) * feature[i][2] >= 0) {
                    ans = max(ans, m2p[i + 1][A - j] +
                                       i2p[i][B - (feature[i][1] - j) *
                                                      feature[i][2]] +
                                       feature[i][0]);
                }
            }
        }
        printf("%d\n", ans);
    }
};

int main() {
    Solution().Solve();
    return 0;
}