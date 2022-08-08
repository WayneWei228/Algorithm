#include <botan/hash.h>
#include <botan/hex.h>

#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

char Buffer[80];

struct Solution {
    unique_ptr<Botan::HashFunction> md5{
        Botan::HashFunction::create("MD5")};
    string S;
    unordered_map<string, string> md5_2017;

    void Set() {
        for (int i = 1; i < 50000; i++) {
            md5_2017[S + to_string(i)] = getHash(S + to_string(i));
        }
    }
    string getHash(string input) {
        for (int i = 0; i < 2017; ++i) {
            md5->update(input);
            input = Botan::hex_encode(md5->final());
        }
        return input;
    }

    bool Check(int k, char e) {
        string match = "";
        for (int i = 0; i < 5; i++) {
            match += e;
        }
        for (int i = k + 1; i <= k + 1000; ++i) {
            md5->update(S + to_string(i));
            string md5ing = Botan::hex_encode(md5->final());
            for (int j = 0; j < int(md5ing.size()) - 4; ++j) {
                if (md5ing.substr(j, 5) == match) {
                    return true;
                }
            }
        }
        return false;
    }

    bool Check2(int k, char e) {
        string match = "";
        for (int i = 0; i < 5; i++) {
            match += e;
        }
        for (int i = k + 1; i <= k + 1000; ++i) {
            string md5ing = md5_2017[S + to_string(i)];
            for (int j = 0; j < int(md5ing.size()) - 4; ++j) {
                if (md5ing.substr(j, 5) == match) {
                    return true;
                }
            }
        }
        return false;
    }

    int Compute1() {
        int k = 1;
        int cnt = 0;
        while (true) {
            bool flag = false;
            md5->update(S + to_string(k));
            string md5Sum = Botan::hex_encode(md5->final());
            for (int i = 0; i < int(md5Sum.size()) - 2; ++i) {
                if (md5Sum[i] == md5Sum[i + 1] &&
                    md5Sum[i] == md5Sum[i + 2]) {
                    if (Check(k, md5Sum[i])) {
                        flag = true;
                    }
                    break;
                }
            }
            if (flag) {
                cnt++;
            }
            if (cnt == 64) {
                return k;
                break;
            }
            k++;
        }
    }

    
    int Compute2() {
        int k = 1;
        int cnt = 0;
        Set();
        while (true) {
            bool flag = false;
            string md5Sum = md5_2017[S + to_string(k)];
            for (int i = 0; i < int(md5Sum.size()) - 2; ++i) {
                if (md5Sum[i] == md5Sum[i + 1] &&
                    md5Sum[i] == md5Sum[i + 2]) {
                    if (Check2(k, md5Sum[i])) {
                        flag = true;
                    }
                    break;
                }
            }
            if (flag) {
                cnt++;
            }
            if (cnt == 64) {
                return k;
                break;
            }
            k++;
        }
    }



    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        printf("%d\n", Compute1());
        printf("%d\n", Compute2());
    }
};

int main() {
    Solution().Solve();
    return 0;
}