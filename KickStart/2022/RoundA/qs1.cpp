#include <cstdio>
#include <string>
using namespace std;

char Buffer1[100005], Buffer2[100005];

struct Solution {
    string s1, s2;
    int ans = 0;
    void Solve(int caseNo) {
        scanf("%s", Buffer1);
        s1 = Buffer1;
        scanf("%s", Buffer2);
        s2 = Buffer2;
        printf("Case #%d: ", caseNo);
        if (s1 != s2 && s1.size() == s2.size()) {
            printf("IMPOSSIBLE\n");
            return;
        }
        if (s1.size() > s2.size()) {
            printf("IMPOSSIBLE\n");
            return;            
        }
        int idx = 0;
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == s1[idx]) {
                idx++;
            } else {
                ans++;
            }
        }
        if (idx == int(s1.size())) {
            printf("%d\n", ans);
        } else {
            printf("IMPOSSIBLE\n");
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}