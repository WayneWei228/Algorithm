#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

char Buffer[100001];

struct BigBinary {
    string Digit;

    void Assign(const string& s) {
        Digit = s;
        reverse(Digit.begin(), Digit.end());
        while (Digit.back() == '0') Digit.pop_back();
        if (Digit.size() == 0) Digit = "0";
    }

    void Assign(int n) {
        Digit.clear();
        while (n != 0) {
            Digit.push_back(n % 2 + '0');
            n /= 2;
        }
        if (Digit.size() == 0) Digit = "0";
    }

    string ToString() const {
        string ans(Digit);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void Add(const BigBinary& that) {
        if (Digit.size() < that.Digit.size()) {
            Digit.resize(that.Digit.size(), '0');
        }
        int carry = 0;
        for (int i = 0; i < Digit.size(); i++) {
            char thatDigit = i < that.Digit.size() ? that.Digit[i] : '0';
            carry += Digit[i] - '0' + thatDigit - '0';
            Digit[i] = (carry % 2) + '0';
            carry /= 2;
        }
        if (carry != 0) Digit.push_back(carry + '0');
    }

    void Minus(const BigBinary& that) {
        int carry = 0;
        for (int i = 0; i < Digit.size(); i++) {
            char thatDigit = i < that.Digit.size() ? that.Digit[i] : '0';
            carry += (Digit[i] - '0') - (thatDigit - '0');
            Digit[i] = (carry + 2) % 2 + '0';
            carry = carry < 0 ? -1 : 0;
        }
        while (2 <= Digit.size() && Digit.back() == '0') {
            Digit.pop_back();
        } 
    }

    int PopCount() const {
        int cnt = 0;
        for (int i = 0; i < Digit.size(); i++) {
            if (Digit[i] == '1') cnt++;
        }
        return cnt;
    }
};

struct Solution {
    int N;
    string A, B;

    void ToFlips(BigBinary& n) {
        n.Add(n); // 二进制乘以二向左移一位，并不会导致1的数量变化
        BigBinary count;
        count.Assign(n.PopCount());
        n.Minus(count);
    }

    BigBinary Flips(const string& a, const string& b) {
        BigBinary a0, b0;
        a0.Assign(a);
        b0.Assign(b);
        ToFlips(b0);
        ToFlips(a0);
        b0.Minus(a0);
        return b0;
    }

    void Solve() {
        scanf("%d", &N);
        scanf("%s", Buffer);
        A = Buffer;
        scanf("%s", Buffer);
        B = Buffer;
        printf("%s\n", Flips(A, B).ToString().c_str());
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) Solution().Solve();
    return 0;
}