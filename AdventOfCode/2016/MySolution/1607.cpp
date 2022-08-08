#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// abba[mnop]qrst

char Buffer[100];

struct IP {
    vector<string> store[2];  // 0 是out, 1 是 in
    vector<string> have_in;
    vector<string> have_out;

    IP(const string& input) {
        int pos = 0;
        // int nchars;
        int d = 0;
        while (true) {
            if (sscanf(input.c_str() + pos, "%[^][\n] ", Buffer) < 1)
                break;
            cout << "Buffer " << Buffer << endl;
            string s = Buffer;
            pos += s.size() + 1;
            store[d].emplace_back(Buffer);
            d = 1 - d;
        }
    }

    bool check(const string& input) {
        for (int i = 0; i < int(input.size()) - 3; ++i) {
            // .size 无符号 要用int强制转换
            if (input[i] == input[i + 3] &&
                input[i + 1] == input[i + 2] &&
                input[i] != input[i + 1]) {
                return true;
            }
        }
        return false;
    }

    void put_in(const string& input) {
        for (int i = 0; i < int(input.size()) - 2; ++i) {
            if (input[i] == input[i + 2] && input[i] != input[i + 1]) {
                have_in.emplace_back(input.substr(i, 3));
            }
        }
        return;
    }

    void put_out(const string& input) {
        for (int i = 0; i < int(input.size()) - 2; ++i) {
            if (input[i] == input[i + 2] && input[i] != input[i + 1]) {
                have_out.emplace_back(input.substr(i, 3));
            }
        }
        return;
    }

    bool check2() {
        for (int i = 0; i < int(have_in.size()); ++i) {
            string temp = "";
            temp += have_in[i][1];
            temp += have_in[i][0];
            temp += have_in[i][1];
            for (int j = i + 1; j < int(have_out.size()); ++j) {
                if (temp == have_out[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};

struct Solution {
    int ans1 = 0, ans2 = 0;
    vector<IP> ips;

    void Solve() {
        while (true) {
            if (scanf("%s", Buffer) < 1) break;
            ips.emplace_back(Buffer);
        }
        for (int i = 0; i < ips.size(); ++i) {
            bool inside = true;
            bool outside = false;
            for (auto j : ips[i].store[0]) {
                if (ips[i].check(j)) {
                    outside = true;
                }
            }
            for (auto j : ips[i].store[1]) {
                if (ips[i].check(j)) {
                    inside = false;
                }
            }
            if (outside && inside) {
                ans1++;
            }
        }

        printf("%d\n", ans1);

        for (int i = 0; i < int(ips.size()); ++i) {
            for (auto j : ips[i].store[0]) {
                ips[i].put_out(j);
            }
            for (auto j : ips[i].store[1]) {
                ips[i].put_in(j);
            }
            if (ips[i].check2()) {
                ans2++;
            }
        }
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}