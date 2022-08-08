#include <botan/hash.h>
#include <botan/hex.h>

#include <array>
#include <cstdio>
#include <limits>
#include <string>
#include <iostream>
using namespace std;

int DX[]{-1, 1, 0, 0}, DY[]{0, 0, -1, 1};

char Buffer[80];

struct Solution {
    unique_ptr<Botan::HashFunction> md5{
        Botan::HashFunction::create("MD5")};
    string S, Path, Argmin, Argmax;
    int minLength = numeric_limits<int>::max();
    int maxLength = numeric_limits<int>::min();

    array<bool, 4> Doors() {
        md5->update(S + Path);
        string md5Sum = Botan::hex_encode(md5->final(), false);
        array<bool, 4> answer;
        for (int i = 0; i < 4; ++i) {
            answer[i] = 'b' <= md5Sum[i] && md5Sum[i] <= 'f';
        }
        return answer;
    }

    void Visit(int x, int y) {
        if (x == 3 && y == 3) {
            int length = Path.size();
            if (length < minLength) {
                minLength = length;
                Argmin = Path;
            }
            if (maxLength < length) {
                maxLength = length;
                Argmax = Path;
            }
            return;
        }
        auto doorsOpen = Doors();
        for (int i = 0; i < 4; ++i) {
            if (!doorsOpen[i]) continue;
            int xNext = x + DX[i];
            if (xNext < 0 || 4 <= xNext) continue;
            int yNext = y + DY[i];
            if (yNext < 0 || 4 <= yNext) continue;
            Path += "UDLR"[i];
            Visit(xNext, yNext);
            Path.pop_back();
        }
    }

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        Visit(0, 0);
        printf("%s\n", Argmin.c_str());
        printf("%d\n", maxLength);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
