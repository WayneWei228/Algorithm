#include <cstdio>
#include <string>
using namespace std;

char Buffer[3000];

struct Solution {
    void Solve() {
        scanf("%s", Buffer);
        string s = Buffer;
        int answer1 = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) answer1 += s[i] - '0';
        }
        if (s[0] == s.back()) answer1 += s[0] - '0';
        printf("%d\n", answer1);
        int answer2 = 0, half = s.size() / 2;
        for (int i = 0; i < half; ++i) {
            if (s[i] == s[i + half]) answer2 += s[i] - '0';
        }
        printf("%d\n", answer2 + answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
