#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

char Buffer[100];

typedef long long int64;

struct Solution {
    string input;
    unordered_map<string, char> m;

    int64 change(int64 time) {
        string s = input;
        int64 shift = 0;
        for (int64 i = 0; i < time; i++) {
            s.insert(0, "....");
            s.append("....");
            // printf("s %s\n", s.c_str());
            string snew(int(s.size() - 4), '.');
            // printf("snew %s\n", snew.c_str());
            for (int64 j = 0; j < s.size() - 4; j++) {
                string temp = s.substr(j, 5);
                snew[j] = m[temp];
            }
            s = move(snew);
            shift += 2;
        }
        int64 ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                ans += i - shift;
            }
        }
        return ans;
    }

    void Solve() {
        scanf("initial state: %s ", Buffer);
        input = Buffer;
        printf("%s\n", input.c_str());
        while (true) {
            char c;
            if (scanf("%s => %s ", Buffer, &c) < 2) break;
            string s = Buffer;
            m.emplace(s, c);
        }
        int dif = change(1001) - change(1000);
        printf("%lld\n", change(20));
        printf("%lld\n", change(1000) + dif * (50000000000 - 1000));
        
    }
};

int main() {
    Solution().Solve();
    return 0;
}