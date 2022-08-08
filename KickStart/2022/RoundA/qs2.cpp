#include <cstdio>
#include <string>
using namespace std;

char Buffer[200000];

struct Solution {
    string s;
    int ts = 0;
    void Solve(int caseNo) {
        scanf("%s", Buffer);
        s = Buffer;

        for (int i = 0; i < s.size(); i++) {
            ts += s[i] - '0';
        } 
        char add;
        if (ts % 9 == 0) {
            add = '0';
        } else {
            add =  9 - (ts % 9) + '0';
        }
        bool flag = false;
        printf("Case #%d: ", caseNo);
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 && add == '0') continue;
            if (add < s[i]) {
                s.insert(s.begin() + i, add);
                printf("%s\n", s.c_str());
                return;
            }
        }
        s += add;
        printf("%s\n", s.c_str());
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 