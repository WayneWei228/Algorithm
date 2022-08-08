#include <cstdio>
#include <unordered_set>
#include <string>
using namespace std;

typedef long long int64;

struct Solution {
    int64 A;
    unordered_set<int> S;
    int64 ans = 0;

    bool isPalindrome (const string& s) {
        int mid = int(s.size()) / 2;
        for (int i = 0; i < mid; i++) {
            if (s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    }

    void Solve(int caseNo) {
        scanf("%lld", &A);
        for (int64 i = 1; i * i <= A; i++) {
            if (A % i == 0) {
                S.emplace(i);
                S.emplace(A / i);
            }
        }
        for (auto i : S) {
            string s = to_string(i);
            if (isPalindrome(s)) {
                ans++;
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