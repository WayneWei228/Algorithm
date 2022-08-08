#include <cmath>
#include <cstdio>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

struct Solution {
    int N, C;
    vector<int> V;  // point
    vector<vector<int>> Near;
    set<int> point;
    set<set<int>> answer;
    void Go(int a, int b, int c) {
        for (auto i : Near[a]) {
            for (auto j : Near[b]) {
                for (auto k : Near[c]) {
                    set<int> temp;
                    temp.emplace(i);
                    temp.emplace(j);
                    temp.emplace(k);
                    printf("temp\n");
                    for (auto i : temp) {
                        printf("%d ", i);
                    }
                    printf("\n");
                    answer.emplace(move(temp));
                }
            }
        }
    }

    void Solve() {
        scanf("%d%d", &N, &C);
        Near.resize(C + 1);
        double half = C / 2;
        for (int i = 0; i < N; i++) {
            int a;
            scanf("%d", &a);
            Near[a].emplace_back(i + 1);
            point.emplace(a);
        }
        for (auto i : point) {
            V.emplace_back(i);
        }
        for (auto i : V) {
            printf("%d ", i);
        }
        printf("\n");
        for (int i = 0; i < V.size(); i++) {
            for (int j = i + 1; j < V.size(); j++) {
                if (V[i] - V[j] == C) continue;
                double low = fmod((V[i] + half), C);
                double high = fmod((V[j] + half), C);
                printf("%d %d %lf %lf\n", V[i], V[j], low, high);
                if (low > high) swap(low, high);
                printf("%d ", int(ceil(low)));
                printf("%d\n", int(floor(high)));
                if (int(V[i]) == int(ceil(low))) continue;
                if (int(V[i]) == int(floor(high))) continue;
                for (int k = int(ceil(low)) + 1; k < int(floor(high)); k++) {
                    printf("K %d\n", k);
                    if (Near[k].size() != 0) {
                        Go(V[i], V[j], k);
                    }
                }
            }
        }
        for (auto i : answer) {
            for (auto j : i) {
                printf("%d ", j);
            }
            printf("\n");
        }
        printf("%d\n", int(answer.size()));
    }
};

int main() {
    Solution().Solve();
    return 0;
}