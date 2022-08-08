#include <cstdio>
#include <string>
#include <unordered_set>
using namespace std;

int M = 1000000007;

char Buffer[1001];

struct Solution {
    string S;

    void Solve(int caseNo) {
        scanf("%s", Buffer);
        S = Buffer;
        int answer = 1;
        for (int i = 0; i < S.size(); ++i) {
            unordered_set<char> u;
            if (i != 0) u.emplace(S[i - 1]);
            u.emplace(S[i]);
            if (i != S.size() - 1) u.emplace(S[i + 1]);
            answer = answer * u.size() % M;
        }
        printf("Case #%d: %d\n", caseNo, answer);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}