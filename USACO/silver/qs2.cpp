#include <cstdio>
#include <utility>
using namespace std;

const int M = 5e6 + 5;
int isPrime[M];
int steps[M];

struct Solution {
    int N;

    int Steps(int i) {
        if (steps[i] != 0) {
            return steps[i];
        }
        if (i % 2 == 0) {
            return steps[i] = i / 2;
        } else {
            for (int j = i; j >= 0; j -= 4) {
                if (isPrime[j] == 0) {
                    return steps[i] = 1 + (i - j) / 2;
                }
            }
        }
        return 0;
    }

    void Solve() {
        scanf("%d", &N);
        int ws = 1e9, wr = 1e9, ls = 1e9, lr = 1e9;
        for (int i = 1; i <= N; i++) {
            int x;
            scanf("%d", &x);
            int s = Steps(x) / 2;
            if (x % 4 == 0) {
                if (s < ls) {
                    ls = s;
                    lr = i;
                } else if (ls == s && lr > i) {
                    lr = i;
                }
            } else {
                if (s < ws) {
                    ws = s;
                    wr = i;
                } else if (ws == s && wr > i) {
                    wr = i;
                }
            }
        }
        if (ws > ls || (ws == ls && wr > lr)) {
            printf("Farmer Nhoj\n");
        } else {
            printf("Farmer John\n");
        }
    }
};

int main() {
    isPrime[0] = 1;
    isPrime[1] = 1;
    for (int i = 2; i <= M; i++) {
        for (int j = i + i; j <= M; j += i) {
            isPrime[j] = 1;
        }
    }

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        Solution().Solve();
    }
    return 0;
}