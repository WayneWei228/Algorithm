#include <cstdio>
#include <string>
using namespace std;

char Buffer[33];

struct Solution {
    string S2, S3;

    string ToString(int x, int base) {
        string ans;
        while (x >= 0) {
            ans += '0' + x % base;
            x /= base;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int Similar(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) diff++;
        }
        return diff == 1;
    }

    int Compute() {
        for (int i = 0; i < S2.size(); i++) {
            S2[i] ^= 1;
            int x = strtol(S2.c_str(), nullptr, 2);
            if (Similar(ToString(x, 3), S3)) return x;
            S2[i] ^= 1;
        }
        return -1;
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