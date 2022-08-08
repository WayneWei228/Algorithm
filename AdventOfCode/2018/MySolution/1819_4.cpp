#include <cstdio>
using namespace std;

typedef long long int64;

int main() {
    int64 a;
    int64 c = 2 * 2 * 19 * 11 + 6 * 22 + 9;
    int64 d = 6 * 22 + 9;
    if (a == 1) {
        c += (27 * 28 + 29) * 30 * 14 * 32;
    }
    a = 0;
    for (int64 e = 1; e <= c; e++) {
        for (int64 b = 1; b <= c; b++) {
            if (e * b == c) a += e;
        }
    }
    printf("%lld\n", a);
}