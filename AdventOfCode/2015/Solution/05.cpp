#include <cstdio>
#include <string>
#include <unordered_set>
using namespace std;

char Buffer[22];

struct Solution {
    void Solve() {
        int answer1 = 0, answer2 = 0;
        while (true) {
            if (scanf("%s", Buffer) < 1) break;
            string s = Buffer;
            int vowel = 0;
            bool twice = false, ban = false;
            for (int i = 0;; ++i) {
                switch (s[i]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        ++vowel;
                }
                if (i + 1 == s.size()) break;
                if (s[i] == s[i + 1]) twice = true;
                if ((s[i] == 'a' && s[i + 1] == 'b') ||
                    (s[i] == 'c' && s[i + 1] == 'd') ||
                    (s[i] == 'p' && s[i + 1] == 'q') ||
                    (s[i] == 'x' && s[i + 1] == 'y')) {
                    ban = true;
                }
            }
            answer1 += vowel >= 3 && twice && !ban;
            unordered_set<int> u;
            bool xyxy = false, xyx = false;
            int lastTwo = 0;
            for (int i = 0;; ++i) {
                int thisTwo = (s[i] << 8) + s[i + 1];
                if (u.find(thisTwo) != u.end()) xyxy = true;
                if (i) u.emplace(lastTwo);
                if (i + 2 == s.size()) break;
                if (s[i + 1] && s[i] == s[i + 2]) xyx = true;
                lastTwo = thisTwo;
            }
            answer2 += xyxy && xyx;
        }
        printf("%d\n%d\n", answer1, answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
