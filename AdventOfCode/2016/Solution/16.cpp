#include <cstdio>
#include <string>
using namespace std;

char Buffer[80];

struct Solution {
    void Dragon(string& s) {
        s += '0';
        for (int i = s.size() - 2; i >= 0; --i) {
            s += s[i] ^ 1;
        }
    }

    void DragonUntil(string& seed, int n) {
        while (seed.size() < n) Dragon(seed);
        seed.resize(n);
    }

    string CheckSum(string&& s) {
        while (s.size() % 2 == 0) {
            string s0(s.size() / 2, '0');
            for (int i = 0; i < s.size(); i += 2) {
                if (s[i] == s[i + 1]) ++s0[i / 2];
            }
            s = move(s0);
        }
        return s;
    }

    void Solve() {
        scanf("%s", Buffer);
        string s1 = Buffer, s2 = Buffer;
        DragonUntil(s1, 272);
        printf("%s\n", CheckSum(move(s1)).c_str());
        DragonUntil(s2, 35651584);
        printf("%s\n", CheckSum(move(s2)).c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}