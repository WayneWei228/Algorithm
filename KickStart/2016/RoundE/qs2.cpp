#include <cstdio>
#include <string>
using namespace std;

typedef long long int64;

struct Solution {
    int64 N;

    bool transform(int64 number, int base) {
        while (number != 0) {
            if (number % base != 1) return false;
            number /= base;
        }
        return true;
    };

    void Solve(int caseNo) {
        scanf("%lld", &N);
        int base = 2;
        while (true) {
            if (transform(N, base)) {
                printf("Case #%d: %d\n", caseNo, base);
                return;
            }
            base++;
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 