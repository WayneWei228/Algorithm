#include <cstdio>
#include <limits>
#include <stack>
#include <string>
using namespace std;

char Buffer[50001];

struct Solution {
    string S;

    int React(char ignore) {
        stack<char> s;
        for (char i : S) {
            // 一个字母的 小写 ^ 大写 == 32
            // 大写 ^ 32 == 小写
            // 小写 ^ 32 == 大写
            // 0 ^ 任意数 = 任意数
            // 忽略 ignore 和 他的大小写
            if (i == ignore || i == (ignore ^ 32)) continue;
            // 前一个跟现在是大小写关系，删掉前一个
            if (!s.empty() && (s.top() ^ i) == 32) {
                s.pop();
            } else {
                s.emplace(i);
            }
        }
        return s.size();
    }

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        printf("%d\n", React(0));
        int answer = numeric_limits<int>::max();
        for (char i = 'a'; i <= 'z'; ++i) {
            int answer0 = React(i);
            if (answer0 < answer) answer = answer0;
        }
        printf("%d\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}