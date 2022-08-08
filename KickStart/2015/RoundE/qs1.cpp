#include <cstdio>
#include <string>
#include <unordered_set>
using namespace std;

typedef long long int64;

int64 Mod = 1000000007;

char Buffer[1005];

struct Solution {
    string input;
    int64 ans = 1;

    void Solve(int caseNo) {
        scanf("%s", Buffer);
        input = Buffer;
        for (int i = 0; i < input.size(); i++) {
            unordered_set<char> s;
            for (int j = -1; j <= 1; j++) {
                if (i + j >= 0 && i + j < int(input.size())) {
                    s.emplace(input[i + j]);
                }
            }
            ans = ans * int(s.size()) % Mod;
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