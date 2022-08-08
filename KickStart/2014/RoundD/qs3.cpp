#include <cstdio>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

char Buffer1[100], Buffer2[100];

struct Solution {
    int N;
    unordered_map<string, int> MapToNumber;
    unordered_map<int, string> NumToMap;
    vector<pair<int, int>> V;
    void Solve(int caseNo) {
        scanf("%d", &N);
        auto toNumber = [&](const string& s) {
            return MapToNumber.emplace(s, MapToNumber.size()).first->second;
        };
        for (int i = 0; i < N; i++) {
            scanf("%s", Buffer1);
            scanf("%s", Buffer2);
            int v0 = toNumber(Buffer1) + 1;
            NumToMap[v0] = Buffer1;
            if (V.size() <= v0) V.resize(v0 + 1);
            int v1 = toNumber(Buffer2) + 1;
            NumToMap[v1] = Buffer2;
            if (V.size() <= v1) V.resize(v1 + 1);
            V[v0].second = v1;
            V[v1].first = v0;
        }
        int start;
        for (int i = 1; i < V.size(); i++) {
            if (V[i].first == 0) {
                start = i;
                break;
            }
        }
        printf("Case #%d:", caseNo);
        while (V[start].second != 0) {
            printf(" %s-%s", NumToMap[start].c_str(), NumToMap[V[start].second].c_str());
            start = V[start].second;
        }
        printf("\n");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 