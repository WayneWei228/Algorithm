#include <cstdio>
#include <unordered_set>
#include <string>
using namespace std;

char Buffer[50];

struct Solution {
    int N;
    string largest;
    int ans = 0;

    void Solve(int caseNo) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf(" %[^\r\n]",  Buffer);
            string input = Buffer;
            unordered_set<char> s;
            for (auto i : input) {
                if (i == ' ') continue;
                s.emplace(i);
            }
            if ((int)s.size() > ans) {
                largest = input;
                ans = int(s.size());
            }
            else if (int(s.size()) == ans) {
                if (largest > input) {
                    largest = input;
                }
            }
        }
        printf("Case #%d: %s\n", caseNo, largest.c_str());
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 