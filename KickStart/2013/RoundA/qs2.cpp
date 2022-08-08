#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> Match{
    "",          "",          "double",   "triple",
    "quadruple", "quintuple", "sextuple", "septuple",
    "octuple",   "nonuple",   "decuple",
};

vector<string> Match1{
    "zero", "one",   "two",   "three", "four", "five",
    "six",  "seven", "eight", "nine",  "ten",
};

int T;

char Buffer[200];

struct Solution {
    string number;
    vector<int> format;

    void Read(const string& s) {
        int i = 0;
        while (i < int(s.size())) {
            int j = 1;
            int cnt = 1;
            while (i + j < int(s.size()) && s[i + j] == s[i]) {
                cnt++;
                j++;
            }
            if (cnt >= 2 && cnt <= 10) {
                cout << " " << Match[cnt];
            }
            if (cnt > 10) {
                for (int i = 0; i < cnt; i++) {
                    cout << " " << Match1[s[i] - '0'];
                }
                i += cnt;
                continue;
            }
            cout << " " << Match1[s[i] - '0'];
            i += cnt;
        }
    }

    void Solve() {
        scanf("%s ", Buffer);
        number = Buffer;
        int a;
        scanf("%d", &a);
        format.emplace_back(a);
        while (true) {
            int a;
            if (scanf("-%d", &a) < 1) break;
            format.emplace_back(a);
        }
        scanf("%*[\r\n]");
        int idx = 0;
        for (int i = 0; i < format.size(); i++) {
            Read(number.substr(idx, format[i]));
            idx += format[i];
        }
        cout << endl;
    }
};

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ":";
        Solution().Solve();
    }
    return 0;
}
/*
Case #1: one five zero one double two three three triple four
Case #2: one five zero one double two double three triple four
Case #3: one two double two three
*/