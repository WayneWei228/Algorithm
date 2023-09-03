#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    static char s[500005];
    while (scanf("%s", s) == 1) {
        int pre = -1;
        int ans = 0;
        int n = strlen(s);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'X') {
                if (pre == -1) {
                    ans = max(ans, i - 1);
                    pre = i;
                } else {
                    ans = max(ans, (i - pre - 2) / 2);
                    pre = i;
                }
            }
        }
        if (pre != n - 1) {
            ans = max(ans, n - pre - 2);
        }
        printf("%d\n", ans);
    }
    return 0;
};
