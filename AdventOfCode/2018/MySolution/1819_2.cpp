#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;

int main() {
    int64 a, b, c, d, e, f;
    c += 2;
    c *= c;
    c = c * 19;
    c = c * 11;
    d += 6;
    d *= 22;
    d += 9;
    c += d;

    if (a == 1) {
        d = 27;
        d *= 28;
        d += 29;
        d *= 30;
        d *= 14;
        d *= 32;
        c += d;
        a = 0;
    }
    e = 1;
    while (true) {
        b = 1;
        while (true) {
            if (e * b == c) {
                a += e;
            }
            b += 1;
            if (b > c) break;
        }
        e += 1;
        if (e > c) {
            printf("%lld\n", a);
            return 0;
        }
    }
}
