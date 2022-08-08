/*
struct BigBinary;
string Digit;
explicit BigBinary(const string& input);
// 逆序到 Digit,但去掉前导零, 如果是 0 保留一个零.

explicit BigBinary(int input);
// 转换为二进制放进 Digit.

string ToString() const;
// 逆序输出为二进制串.

operator+=(const BigBinary& that);
// 从低位向高位做加法, 记录进位. 最高位可能还有进位.

operator-=(const BigBinary& that);
// 从低位向高位做减法, 记录退位. 保证够减. 去掉结果的前导零.

int PopCount() const;
// 统计二进制表示中有多少个 
*/

/*
struct Solution;
int N;
string A, B;

BigBinary Flips(BigBinary x);
// 求出从 0 到 x 翻转多少次.

BigBinary Flips(const string& a, const string& b);
// 求出从 a 到 b 翻转多少次.

void Solve();
// 解决溢出的情况, 执行输入输出.
*/

#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;

char Buffer[100001];

struct BigBinary {
    string Digit;
    
    explicit BigBinary(const string &input) { 
    // 逆序到 Digit,但去掉前导零, 如果是 0 保留一个零.    
        Digit = input;
        reverse(Digit.begin(), Digit.end());
        while (Digit.back() == '0') {
            Digit.pop_back();
        }
        if (Digit.size() == 0) {
            Digit.push_back('0');
        }
    }

    explicit BigBinary (int input) {
    // 转换为二进制放进 Digit.
        while (input != 0) {
            Digit.push_back(input % 2 + '0');
            input /= 2;
        }
    }

    string ToString() const {
        string answer(Digit);
        reverse(answer.begin(), answer.end());
        return answer;
    }

    void operator+=(const BigBinary &that) {
        // 从低位向高位做加法, 记录进位. 最高位可能还有进位.
        if(that.Digit.size() > Digit.size()) // 保证 Digit 等长或长于 that
            Digit.resize(that.Digit.size(), '0');
        
        int carry = 0;
        for(int i = 0; i < Digit.size(); ++i) {
            int thatDigit = i < that.Digit.size() ? that.Digit[i] : '0';
            carry += (Digit[i] - '0') + (thatDigit - '0');
            Digit[i] = carry % 2 + '0';
            carry /= 2;
        }
        if(carry != 0) Digit.push_back(carry + '0'); // carry还剩 1 作最高位加上去
    }

    void operator-=(const BigBinary &that) {
        // 从低位向高位做减法, 记录退位. 保证够减. 去掉结果的前导零.
        int carry = 0;
        for(int i = 0; i < Digit.size(); i++) {
            int thatDigit = i < that.Digit.size() ? that.Digit[i] : '0';
            carry -= Digit[i] - thatDigit;
            Digit[i] = (carry + 2) % 2 + '0';
            carry = (carry - (carry + 2) % 2) / 2;
        }
        while (2 <= Digit.size() && Digit.back() == '0') {
            Digit.pop_back();
        }
    }

    int PopCount() const {
        int answer = 0; 
        for (int i = 0; i < Digit.size(); i++) {
            if(Digit[i] != '0') {
                ++answer;
            }
        }
        return answer;
    }
};

struct Solution {
    int N;
    string A, B;
    BigBinary Flips(BigBinary x) {
        x += x;
        x -= BigBinary(x.PopCount());
        return x;
    }
    BigBinary Flips(const string & a, const string &b) {
        BigBinary fB = Flips(BigBinary(b));
        BigBinary fA = Flips(BigBinary(a));
        fB -= fA;
        return fB;
    }

    void Solve() {
        scanf("%d", &N);
        scanf("%s", Buffer);
        A = Buffer;
        scanf("%s", Buffer);
        B = Buffer;
        BigBinary answer("");
        if(B < A) {
            answer = Flips(A, '1' + B);
            answer -= BigBinary("1");
        } else {
            answer = Flips(A, B);
        }
        printf("%s\n", answer.ToString().c_str());
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i) {
        Solution().Solve();
    }
    return 0;
}
