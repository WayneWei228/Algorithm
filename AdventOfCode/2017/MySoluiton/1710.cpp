#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[80];

struct Circular {
    int origin[256], no = 0, skipsize = 0;
    int size = 256;

    Circular() {
        for (int i = 0; i < 256; i++) origin[i] = i;
    }

    void Do(int len) {
        int radius = len / 2;
        int left = no, right = (no + len - 1) % size;
        if (len > size) goto Move;
        for (int i = 0; i < radius; ++i) {
            swap(origin[left++ % size],
                 origin[(size + right--) % size]);
        }
    Move:
        no = (no + len + skipsize++) % size;
    }
};

string KnotHash(string&& s) {
    Circular c;
    string ans2 = "";
    s += "\x11\x1f\x49\x2f\x17";
    for (int i = 0; i < 64; i++) {
        for (char j : s) {
            c.Do(j);
        }
    }
    int k = 0;
    for (int i = 0; i < 16; i++) {
        int dense = 0;
        for (int j = 0; j < 16; j++) {
            dense ^= c.origin[k++];
        }
        sprintf(Buffer, "%02x", dense);
        ans2 += Buffer;
    }
    return ans2;
}

struct Solution {
    void Solve() {
        scanf("%s", Buffer);
        string s = Buffer;
        Circular c;
        int pos = 0;
        int nchars = -1;
        vector<int> input;
        while (pos < s.size()) {
            int d;
            char ch;
            sscanf(s.c_str() + pos, "%d%c%n", &d, &ch, &nchars);
            c.Do(d);
            pos += nchars;
        }
        printf("%d\n", c.origin[0] * c.origin[1]);
        printf("%s\n", KnotHash(move(s)).c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}