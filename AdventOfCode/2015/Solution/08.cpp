#include <cstdio>
#include <string>
using namespace std;

char Buffer[80];

struct Solution {
    void Solve() {
        int answer1 = 0, answer2 = 0;
        while (true) {
            if (scanf("%s", Buffer) < 1) break;
            string s = Buffer;
            answer1 += s.size() + 2;
            for (int i = 0; i < s.size();) {
                if (s[i] == '\\') {
                    switch (s[i + 1]) {
                        case '\\':
                            --answer1;
                            i += 2;
                            break;
                        case '"':
                            --answer1;
                            i += 2;
                            break;
                        case 'x':
                            --answer1;
                            i += 4;
                            break;
                    }
                } else {
                    --answer1;
                    ++i;
                }
            }
            answer2 -= s.size() - 2;
            for (int i = 0; i < s.size(); ++i) {
                switch (s[i]) {
                    case '\\':
                        answer2 += 2;
                        break;
                    case '"':
                        answer2 += 2;
                        break;
                    default:
                        ++answer2;
                        break;
                }
            }
        }
        printf("%d\n%d\n", answer1, answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}