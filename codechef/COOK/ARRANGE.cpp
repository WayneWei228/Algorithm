#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[70000];

/*
00001
10000
*/

struct Solution {
    int N;
    string input, output;


    int Reverse(int no) {
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += ans + no % 2;
            no /= 2;
        }
        return ans;
    }

    void Solve() {
        scanf("%d%s", &N, Buffer);
        input = Buffer;
        output.resize(input.size(), '0');
        for (int i = 0; i < input.size(); i++) {
            output[Reverse(i)] = input[i];
        }
        printf("%s\n", output.c_str());
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
} 