#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct CircularList {
    int A[256], Current = 0, Skip = 0;

    CircularList() {
        for (int i = 0; i < 256; ++i) A[i] = i;
    }

    void Transfrom(int length) {
        rotate(&A[0], &A[Current], &A[256]);
        reverse(&A[0], &A[length]);
        rotate(&A[0], &A[256 - Current], &A[256]);
        Current += length + Skip++;
        Current %= 256;
    }
};

char Buffer[80];

string KnotHashAsBinary(string&& input) {
    input += "\x11\x1f\x49\x2f\x17";
    CircularList c;
    for (int i = 0; i < 64; ++i) {
        for (char j : input) c.Transfrom(j);
    }
    input.clear();
    int k = 0;
    for (int i = 0; i < 16; ++i) {
        int dense = 0;
        for (int j = 0; j < 16; ++j) dense ^= c.A[k++];
        for (int j = 7; j >= 0; --j) {
            input += '0' + ((dense >> j) & 1);
        }
    }
    return move(input);
}

int DX[4]{1, 0, -1, 0}, DY[4]{0, 1, 0, -1};

struct Solution {
    string Key;
    vector<string> H;

    void RemoveComponent(int x, int y) {
        H[x][y] = '0';
        for (int i = 0; i < 4; ++i) {
            int xNext = x + DX[i];
            if (xNext < 0 || 128 <= xNext) continue;
            int yNext = y + DY[i];
            if (yNext < 0 || 128 <= yNext) continue;
            if (H[xNext][yNext] != '0') RemoveComponent(xNext, yNext);
        }
    }

    void Solve() {
        scanf("%s", Buffer);
        Key = Buffer;
        int answer1 = 0, answer2 = 0;
        H.resize(128);
        for (int i = 0; i < 128; ++i) {
            H[i] = KnotHashAsBinary(Key + '-' + to_string(i));
            for (char j : H[i]) {
                if (j != '0') ++answer1;
            }
        }
        printf("%d\n", answer1);
        for (int i = 0; i < 128; ++i) {
            for (int j = 0; j < 128; ++j) {
                if (H[i][j] != '0') {
                    RemoveComponent(i, j);
                    ++answer2;
                }
            }
        }
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
