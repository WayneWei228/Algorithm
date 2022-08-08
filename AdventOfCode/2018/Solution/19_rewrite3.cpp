#include <cstdio>
using namespace std;

typedef long long int64;

int main() {
    int64 a = 0, c = 0, d = 0, e = 0, f = 0;
    e = 2 * 2 * 19 * 11;
    c = 6 * 22 + 2;
    e += c;
    if (a == 1) {
        c = (27 * 28 + 29) * 30 * 14 * 32;
        e += c;
        a = 0;
    }
    d = 1;
    while (true) {
        f = 1;
        while (true) {
            if (d * f == e) a += d;
            ++f;
            if (f > e) break;
        }
        ++d;
        if (d > e) {
            printf("%lld\n", a);
            return 0;
        }
    }
}
