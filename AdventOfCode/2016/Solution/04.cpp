#include <cctype>
#include <cstdio>
#include <string>
using namespace std;

char Buffer0[80], Buffer1[80];

struct Solution {
    void Solve() {
        int answer1 = 0, answer2;
        while (true) {
            if (scanf("%[^[][%[^]]] ", Buffer0, Buffer1) < 2) break;
            string s0 = Buffer0, s1 = Buffer1;
            int checksum;
            sscanf(s0.c_str(), "%*[^0123456789]%d", &checksum);
            int count[256]{};
            for (char i : s0) ++count[i];
            char index[26];
            for (int i = 0; i < 26; ++i) index[i] = 'a' + i;
            // & 表示传递方式为引用传递
            stable_sort(index, index + 26, [&](int a0, int a1) {
                return count[a1] < count[a0];
            });
            index[5] = 0;
            // C风格字符串，看见一个0后面都不看，所以只有前五个
            if (s1 == index) answer1 += checksum;
            for (char& i : s0) {
                if (isalpha(i)) i = (i - 'a' + checksum) % 26 + 'a';
            }
            if (s0.substr(0, 9) == "northpole")
                answer2 = checksum;  // s0 后还有东西
        }
        printf("%d\n", answer1);
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}