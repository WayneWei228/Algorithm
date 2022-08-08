#include <botan/hash.h>
#include <botan/hex.h>

#include <cstdio>
#include <memory>
#include <string>
using namespace std;

char Buffer[80];

struct Solution {
    unique_ptr<Botan::HashFunction> md5{
        Botan::HashFunction::create("MD5")};
    string S;

    bool HasZero(const string& md5Sum, int numberZero) {
        for (int i = 0; i < numberZero; ++i) {
            if (md5Sum[i] != '0') return false;
        }
        return true;
    }

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        string answer1(8, '_'), answer2(8, '_');
        int size1 = 0, size2 = 0, k = 0;
        while (size1 < 8 || size2 < 8) {
            md5->update(S + to_string(k));
            string md5Sum = Botan::hex_encode(md5->final(), false);
            if (HasZero(md5Sum, 5)) {
                char c6 = md5Sum[5];
                char c7 = md5Sum[6];
                if (size1 < 8) answer1[size1++] = c6;
                if (size2 < 8 && '0' <= c6 && c6 < '8') {
                    int position = c6 - '0';
                    if (answer2[position] == '_') {
                        answer2[position] = c7;
                        ++size2;
                    }
                }
            }
            ++k;
        }
        printf("%s\n", answer1.c_str());
        printf("%s\n", answer2.c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
