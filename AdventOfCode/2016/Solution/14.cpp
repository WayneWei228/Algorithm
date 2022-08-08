#include <botan/hash.h>
#include <botan/hex.h>

#include <cstdio>
#include <deque>
#include <string>
using namespace std;

struct MD5 {
    unique_ptr<Botan::HashFunction> md5{
        Botan::HashFunction::create("MD5")};

    virtual string Compute(const string& s) {
        md5->update(s);
        return Botan::hex_encode(md5->final(), false);
    }
};

struct MD5_2017 : public MD5 {
    string Compute(const string& s) {
        string answer(s);
        for (int i = 0; i < 2017; ++i) answer = MD5::Compute(answer);
        return answer;
    }
};

char Buffer[80];

struct Solution {
    string S;

    bool Same(const string& s, int k, char& c) {
        int current = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++current;
            } else {
                current = 1;
            }
            if (k == current) {
                if (c == 0) c = s[i];
                if (c == s[i]) return true;
            }
        }
        return false;
    }

    bool Valid(const deque<string>& q) {
        char c = 0;
        if (!Same(q.front(), 3, c)) return false;
        for (int i = 1; i < q.size(); ++i) {
            if (Same(q[i], 5, c)) return true;
        }
        return false;
    }

    void Solve(MD5&& m) {
        deque<string> d;
        int current = 0;
        for (int i = 0; i <= 1000; ++i) {
            d.emplace_back(m.Compute(S + to_string(current++)));
        }
        for (int i = 0; i < 64;) {
            if (Valid(d)) ++i;
            d.pop_front();
            d.emplace_back(m.Compute(S + to_string(current++)));
        }
        printf("%d\n", current - 1002);
    }

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        Solve(MD5());
        Solve(MD5_2017());
    }
};

int main() {
    Solution().Solve();
    return 0;
}