#include <cstdio>
#include <string>
using namespace std;

// A(1x5)BC
// ABBBBBC
typedef long long int int64;

char Buffer[20000];

struct Solution {
    string s;
    int64 ans1 = 0;
    int64 ans2 = 0;
    int64 Count(const string& input, bool recursion) {
        int64 ans = 0;
        for (int64 i = 0; i < int64(input.size());) {
            int l, r, num;
            if (input[i] == '(' && !recursion) {
                sscanf(input.c_str() + i, "(%dx%d)%n", &l, &r, &num);
                ans += l * r;
                i += (num + l);
            } else if (input[i] == '(' && recursion) {
                sscanf(input.c_str() + i, "(%dx%d)%n", &l, &r, &num);
                int64 next = r * Count(input.substr(i + num, l), 1);
                ans += next;
                i += (num + l);
            } else {
                ans++;
                i++;
            }
        }
        return ans;
    }

    void Solve() {
        scanf("%s", Buffer);
        s = Buffer;
        ans1 = Count(s, false);
        ans2 = Count(s, true);
        printf("%lld\n", ans1);
        printf("%lld\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}