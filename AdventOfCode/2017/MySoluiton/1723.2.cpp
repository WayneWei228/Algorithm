#include <cstdio>
#include <string>
using namespace std;

typedef long long int int64;

int main() {
    int64 b = 0;
    int64 g = 0;
    int64 a = 1;
    int64 c = 0;
    int64 h = 0;
    int64 f = 0, d = 0, e = 0;

    b = 106500;
    c = 123500;  // 8

    while (true) {
        f = 1;  // 9
        d = 2;  // 10
        e = 2;  // 11

        g = 4 - b;
        if (g == 0) {  // 15
            f = 0;     // 16
        }
        e = 3;      // 17
        g = 3 - b;  // 19

        if (b % 2 == 0) f = 0;

        g = 3 - b;  // 23

        while (g != 0) {
            g = d * 2 - b;
            if (g == 0) {  // 15
                f = 0;     // 16
            }
            g = 3 - b;  // 19
            if (b % d == 0) f = 0;
            d += 1;     // 21
            g = d - b;  // 23
        }

        if (f == 0) {  // 25
            h += 1;    // 26
        }
        g = b - 123500;  // 28
        if (g == 0) {    // 29
            break;
        }
        b += 17;  // 31
    }
    printf("%lld\n", h);
}