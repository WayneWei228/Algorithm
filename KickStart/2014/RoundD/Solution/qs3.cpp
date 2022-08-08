#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

char Buffer[80];

struct Solution {
    int N;
    unordered_map<string, string> F;
    unordered_set<string> S;

    void Solve(int caseNo) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%s", Buffer);
            string s0 = Buffer;
            scanf("%s", Buffer);
            string s1 = Buffer;
            F[s0] = s1;
            S.emplace(s0);
        }
        for (const auto& i : F) S.erase(i.second); // 能到达的都不是头
        string begin = *S.begin(); // 找到头
        printf("Case #%d:", caseNo);
        while (true) {
            auto next = F.find(begin);
            if (next == F.end()) break;
            printf(" %s-%s", begin.c_str(), next->second.c_str());
            begin = next->second;
        }
        printf("\n");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}