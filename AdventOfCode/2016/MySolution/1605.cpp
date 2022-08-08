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
    string ans1 = "";
    string ans2 = "........";

    bool HasZero(const string& md5Sum, int numberZero) {
        for (int i = 0; i < numberZero; ++i) {
            if (md5Sum[i] != '0') return false;
        }
        return true;
    }

    int Compute(int numberZero) {
        int k = 0;
        int i = 0;
        while (i < 8) {
            md5->update(S + to_string(k));
            string md5Sum = Botan::hex_encode(md5->final());
            if (HasZero(md5Sum, numberZero)) {
                ans1 += md5Sum[5];
                if (md5Sum[5] >= '0' && md5Sum[5] <= '7') {
                    ans2[md5Sum[5]] = md5Sum[6];
                }
                i++;
            }
            k++;
        }
        k = 0;
        i = 0;
        while (i < 8) {
            md5->update(S + to_string(k));
            string md5Sum = Botan::hex_encode(md5->final());
            if (HasZero(md5Sum, numberZero)) {
                if (md5Sum[5] >= '0' && md5Sum[5] <= '7' &&
                    ans2[md5Sum[5] - '0'] == '.') {
                    ans2[md5Sum[5] - '0'] = md5Sum[6];
                    i++;
                }
            }
            k++;
        }
        printf("%s\n", ans1.c_str());
        printf("%s\n", ans2.c_str());
    }

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        Compute(5);
    }
};

int main() {
    Solution().Solve();
    return 0;
}