#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

struct CircularList {
    int A[256], Current = 0, Skip = 0;

    CircularList() {
        for (int i = 0; i < 256; ++i) A[i] = i;
    }

    void Transfrom(int length) {
        rotate(&A[0], &A[Current], &A[256]); // 像左移
        reverse(&A[0], &A[length]); // 翻转
        rotate(&A[0], &A[256 - Current], &A[256]); // 向右归正
        Current += length + Skip++;
        Current %= 256;
    }
};

char Buffer[80];

string KnotHash(string&& input) {
    input += "\x11\x1f\x49\x2f\x17";
    printf("%s\n", input.c_str());
    CircularList c;
    for (int i = 0; i < 64; ++i) {
        for (char j : input) c.Transfrom(j);
    }
    input.clear();
    int k = 0;
    for (int i = 0; i < 16; ++i) {
        int dense = 0;
        for (int j = 0; j < 16; ++j) dense ^= c.A[k++];
        sprintf(Buffer, "%02x", dense);
        input += Buffer;
    }
    return move(input);
}

struct Solution {
    vector<int> A;

    void Solve() {
        scanf("%[^\n]", Buffer);
        string s = Buffer;
        CircularList c;
        int p = 0;
        while (true) {
            int x, nchars = 0;
            if (sscanf(s.c_str() + p, "%d%n", &x, &nchars) < 1) break;
            c.Transfrom(x);
            p += nchars;
            if (s.c_str()[p] == ',') ++p;
        }
        printf("%d\n", c.A[0] * c.A[1]);
        printf("%s\n", KnotHash(move(s)).c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
