#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

char Buffer[80];

struct Solution {
    string input;

    string GenerateData(const string& s) {
        string ans = "";
        string b(s);
        string after = "";
        for (int i = int(b.size()) - 1; i >= 0; i--) {
            after += 97 - b[i];
        }
        ans += s;
        ans += '0';
        ans += after;
        return ans;
    }

    string GetData(const string& input, int Length) {
        string s = input;
        while (int(s.size()) < Length) {
            s = GenerateData(s);
        }
        return s.substr(0, Length);
    }

    string GetCheckSum(const string& input) {
        string s = "";
        for (int i = 0; i < int(input.size()) - 1; i += 2) {
            if (input[i] == input[i + 1]) {
                s += '1';
            } else {
                s += '0';
            }
        }
        if (int(s.size()) % 2 == 1) {
            return s;
        } else {
            return GetCheckSum(s);
        }
    }

    void Solve() {
        scanf("%s", Buffer);
        input = Buffer;
        string data = GetData(input, 272);
        printf("%s\n", GetCheckSum(data).c_str());
        data = GetData(input, 35651584);
        printf("%s\n", GetCheckSum(data).c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}