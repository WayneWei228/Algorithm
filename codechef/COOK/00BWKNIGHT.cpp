#include <cstdio>
#include <string>
#include <vector>
using namespace std;
// ./BWKNIGHT.bin

typedef long long int64;

const int M = 1000000000;  // 九位

char Buffer[80];

struct BigUnsigned {
    vector<int> Digit; 

    // 每九位存一次，从个位往上走，
    void Assign(const string& s) {
        Digit.clear();
        for (int i = s.size() - 1; i >= 0; i -= 9) {
            int start = max(0, i - 8);
            Digit.emplace_back(stol(s.substr(start, i - start + 1)));
        }
        // Digit[0] 存 个9位，往上走
    }

    string ToString() {
        string output;
        bool head = true;
        for (int i = Digit.size() - 1; i >= 0; i--) {
            sprintf(Buffer, head ? "%d" : "%09d", Digit[i]);
            head = false;
            output += Buffer;
        }
        return output;
    }

    void Minus(const BigUnsigned& that) {
        int carry = 0;
        for (int i = 0; i < Digit.size(); i++) {
            int thatdigit = i < that.Digit.size() ? that.Digit[i] : 0;
            carry += Digit[i] - thatdigit;
            Digit[i] = (carry + M) % M;
            carry = carry < 0 ? -1 : 0;
        }
        while (2 <= Digit.size() && Digit.back() == 0) Digit.pop_back();
    }

    void Times(int64 that) {
        int64 carry = 0;
        for (int i = 0; i < Digit.size(); i++) {
            carry += Digit[i] * that;
            Digit[i] = carry % M;
            carry /= M;
        }
        if (carry != 0) Digit.emplace_back(carry);
    }
};

struct Solution {
    int N, M;
    BigUnsigned ans;
    void Solve() {
        scanf("%d%d", &N, &M);
        BigUnsigned one;
        one.Assign("1");
        ans.Assign(to_string(N));
        ans.Times(M);
        ans.Minus(one);
        ans.Times(M);
        ans.Times(N);
        if (2 > N || 2 > M) {
            printf("%s\n", ans.ToString().c_str());
            return;
        }
        BigUnsigned b1, b2;
        b1.Assign(to_string(N - 2));
        b1.Times(4);
        b1.Times(M - 1);
        b2.Assign(to_string(N - 1));
        b2.Times(4);
        b2.Times(M - 2);
        ans.Minus(b1);
        ans.Minus(b2);
        printf("%s\n", ans.ToString().c_str());
        // if (N < 2 || M < 2) {
        //     ans = N * M * (N * M - 1);
        // } else {
        //     ans = N * M * (N * M - 1) - 4 * ((N - 2) * (M - 1) + (N -
        //     1) * (M - 2));
        // }
        // printf("%lld\n", ans);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}