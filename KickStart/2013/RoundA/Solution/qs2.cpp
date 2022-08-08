#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[200];

const char* CountWord[11]{
    "",          "",          "double",   "triple",
    "quadruple", "quintuple", "sextuple", "septuple",
    "octuple",   "nonuple",   "decuple",
};

const char* DigitWord[10]{
    "zero", "one", "two",   "three", "four",
    "five", "six", "seven", "eight", "nine",
};

struct Solution {
    bool Head = true;

    void Solve(int caseNo) {
        scanf("%s", Buffer);
        string s = Buffer;
        vector<int> split;
        char c;
        do {
            int n;
            scanf("%d", &n);
            split.emplace_back(n);
            scanf("%c", &c);
        } while (c == '-');
        printf("Case #%d: ", caseNo);
        int position = 0;
        for (int i : split) {
            Print(s.substr(position, i));
            position += i;
        }
        printf("\n");
    }

    void Print(const string& s) {
        // p 存储每次变化的位置
        // 0 开始有数
        // 左闭右开 求length
        vector<int> p{0};
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] != s[i]) p.emplace_back(i);
        }
        // 最终变成“没有了”也相当于变化了
        p.emplace_back(s.size());
        for (int i = 1; i < p.size(); i++) {
            int count = p[i] - p[i - 1];
            int digit = s[p[i - 1]] - '0';
            if (10 < count) {
                // 超过 10个 一个一个单独输出
                for (int j = 0; j < count; ++j) {
                    PrintDigit(digit);
                }
            } else {
                // 
                PrintCount(count);
                PrintDigit(digit);
            }
        }
    }

    void PrintCount(int count) {
        // 等于 1，啥也不输出
        if (count != 1) PrintSpace();
        printf("%s", CountWord[count]);
    }

    void PrintDigit(int digit) {
        PrintSpace();
        printf("%s", DigitWord[digit]);
    }

    void PrintSpace() {
        if (Head) {
            Head = false;
        } else {
            printf(" ");
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}