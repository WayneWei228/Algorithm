#include <cstdio>
using namespace std;

typedef long long int64;

int main() {
    int64 a = 0, c = 0, d = 0, e = 0, f = 0;
    e = e + 2;
    e = e * e;
    e = 19 * e;
    e = e * 11;
    c = c + 6;
    c = c * 22;
    c = c + 2;
    e = e + c;
    if (a == 1) {
        c = 27;
        c = c * 28;
        c = 29 + c;
        c = 30 * c;
        c = c * 14;
        c = c * 32;
        e = e + c;
        a = 0;
    }
    d = 1;
    while (true) {
        f = 1;
        while (true) {
            if (d * f == e) {
                a = d + a;
            }
            f = f + 1;
            if (f > e) break;
        }
        d = d + 1;
        if (d > e) {
            printf("%lld\n", a);
            return 0;
        }
    }
}
