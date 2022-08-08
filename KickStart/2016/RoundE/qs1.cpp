#include <cstdio>
#include <string>
using namespace std;

char Buffer[105];

typedef long long int64;

struct Solution {
    string pattern;
    int64 L, R;
    int blueN = 0;
    int64 ans = 0; 

    void Solve(int caseNo) {
        scanf("%s", Buffer);
        pattern = Buffer;
        scanf("%lld%lld", &L, &R);
        for (auto i : pattern) {
            if (i == 'B') {
                blueN++;
            }
        }
        R += 1;
        if (int(pattern.size()) == 1) {
            if (pattern[0] == 'B') {
                printf("Case #%d: %lld\n", caseNo, R - L);
            } else {
                printf("Case #%d: %d\n", caseNo, 0);
            }
            return;
        }
        int64 start = L % int(pattern.size());
        while (L < R && start != 1) {
            if (start == 0) {
                ans += (pattern.back() == 'B');
            } else {
                ans += (pattern[start - 1] == 'B');
            }
            L++;
            start++;
            if (start == int(pattern.size())) {
                start = 0;
            }
        }
        int64 nstring = (R - L) / int(pattern.size());
        ans += nstring * blueN;
        L += nstring * int(pattern.size());
        for (int i = 0; i < R - L; i++) {
            ans += (pattern[i] == 'B');
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