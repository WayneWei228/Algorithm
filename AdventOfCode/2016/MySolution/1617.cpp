#include <botan/hash.h>
#include <botan/hex.h>

#include <array>
#include <cstdio>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>
using namespace std;

char Buffer[80];

struct Solution {
    unique_ptr<Botan::HashFunction> md5{
        Botan::HashFunction::create("MD5")};

    string S;
    string direction = "UDLR";
    int next[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int shorest = numeric_limits<int>::max();
    string shorest_path = "";
    int longest = numeric_limits<int>::min();

    string getMD5(string& input) {
        md5->update(input);
        return Botan::hex_encode(md5->final(), false).substr(0, 4);
    }

    array<bool, 4> Paths(const string& input) {
        array<bool, 4> arr;
        for (int i = 0; i < input.size(); ++i) {
            if ('b' <= input[i] && input[i] <= 'f') {
                arr[i] = true;
            } else {
                arr[i] = false;
            }
        }
        return arr;
    }

    bool Finish(int x, int y) {
        if (x == 3 && y == 3) {
            return true;
        }
        return false;
    }

    void Go(int x, int y, string record) {
        if (Finish(x, y)) {
            if (int(record.size()) < shorest) {
                shorest = int(record.size());
                shorest_path = record;
            }
            if (int(record.size()) > longest) {
                longest = int(record.size()) - int(S.size());
            }
            return;
        }

        cout << getMD5(record) << endl;
        array<bool, 4> path = Paths(getMD5(record));

        for (int i = 0; i < path.size(); ++i) {
            if (path[i]) {
                int xNext = x + next[i][0];
                if (xNext < 0 || xNext > 3) continue;
                int yNext = y + next[i][1];
                if (yNext < 0 || yNext > 3) continue;
                Go(xNext, yNext, record + direction[i]);
            }
        }
    }

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        Go(0, 0, S);
        printf("%s\n", shorest_path.c_str());
        printf("%d\n", longest);
    }
};

int main() {
    Solution().Solve();
    return 0;
}