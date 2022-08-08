#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

char Buffer[33];

struct Solution {
    string S2, S3;

    string ToString(int x, int base) {
        string answer;
        while (x > 0) {
            answer += '0' + x % base;
            x /= base;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }

    bool Similar(const string& s0, const string& s1) {
        if (s0.size() != s1.size()) return false;
        int difference = 0;
        for (int i = 0; i < s0.size(); ++i) {
            if (s0[i] != s1[i]) ++difference;
        }
        return difference == 1;
    }

    int Compute() {
        for (int i = 0; i < S2.size(); ++i) {
            S2[i] ^= 1; // '0' -> '1' or '1' -> '0'
            int x = strtol(S2.c_str(), nullptr, 2); // 该string 在 二进制下 体现的值
            if (Similar(ToString(x, 3), S3)) return x;
            S2[i] ^= 1;
        }
        return 0;
    }

    void Solve() {
        scanf("%s", Buffer);
        S2 = Buffer;
        scanf("%s", Buffer);
        S3 = Buffer;
        printf("%d\n", Compute());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
