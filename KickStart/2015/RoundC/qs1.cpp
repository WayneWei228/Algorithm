#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

char Buffer[80];

struct Solution {
    int P, N, M;
    map<string, vector<int>> athletes;
    map<int, vector<string>> rank;
    vector<int> S;
    void Solve(int caseNo) {
        scanf("%d", &P);
        S.resize(P);
        for (int i = 0; i < P; i++) {
            scanf("%d", &S[i]);
        }
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int w;
            scanf("%d", &w);
            for (int j = 0; j < P; j++) {
                scanf("%s", Buffer);
                string athlete = Buffer;
                athletes[athlete].emplace_back(w * S[j]);
            }
        }
        for (auto& i : athletes) {
            sort(i.second.begin(), i.second.end(), [&](int a, int b) {
                return a > b;
            });
        }
        scanf("%d", &M);
        for (auto i : athletes) {
            int score = 0;
            for (int j = 0; j < M; j++) {
                if (j >= i.second.size()) break;
                score += i.second[j];
            }
            rank[score].emplace_back(i.first);
        }
        printf("Case #%d:\n", caseNo);
        int d = 1;
        for (auto it = rank.rbegin(); it != rank.rend(); it++) {
            int t = 0;
            for (auto j : it->second) {
                printf("%d: %s\n", d, j.c_str());
                t++;
            }
            d += t;
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 