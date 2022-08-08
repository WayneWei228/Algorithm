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

    int Compute(int numberZero) {
        int k = 1;
        while (true) {
            md5->update(S + to_string(k));
            string md5Sum = Botan::hex_encode(md5->final());
            if (HasZero(md5Sum, numberZero)) return k;
            ++k;
        }
    }

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        printf("%d\n", Compute(5));
        printf("%d\n", Compute(6));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
