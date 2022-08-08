#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[11];

struct Athlete {
    string Name;
    int Score;

    bool operator<(const Athlete& that) const {
        if (that.Score != Score) return that.Score < Score;
        return Name < that.Name;
    }
};

struct Solution {
    int P, N, W, M;
    vector<int> S;
    unordered_map<string, vector<int>> Score;
    vector<Athlete> A;

    void Solve(int caseNo) {
        scanf("%d", &P);
        S.resize(P);
        for (int i = 0; i < P; ++i) scanf("%d", &S[i]);
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &W);
            for (int j = 0; j < P; ++j) {
                scanf("%s", Buffer);
                Score[Buffer].emplace_back(S[j] * W);
            }
        }
        scanf("%d", &M);
        for (auto& i : Score) {
            sort(i.second.begin(), i.second.end(),
                 [](int a0, int a1) { return a1 < a0; });
            i.second.resize(M);
            Athlete a{i.first, 0};
            for (int j = 0; j < M; ++j) a.Score += i.second[j];
            A.emplace_back(a);
        }
        sort(A.begin(), A.end());
        printf("Case #%d:\n", caseNo);
        int k0 = 1, k1 = 1, lastScore = 0;
        for (const Athlete& i : A) {
            if (i.Score != lastScore) k1 = k0;
            lastScore = i.Score;
            printf("%d: %s\n", k1, i.Name.c_str());
            ++k0;
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}