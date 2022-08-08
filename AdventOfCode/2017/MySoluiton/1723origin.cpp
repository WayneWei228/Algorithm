#include <cstdio>
#include <string>
using namespace std;

int main() {
    int b = 0;
    int g = 0;
    int a = 1;
    int c = 0;
    int h = 0;
    int f = 0, d = 0, e = 0;

    b = 65;        // 1
    c = b;         // 2
    if (a != 0) {  // 3
        goto Label_1;
    } else {
        goto Label_2;
    }
Label_1:
    b *= 100;     // 5
    b += 100000;  // 6
    c = b;        // 7
    c += 17000;   // 8
Label_2:          // 9
    while (true) {
        f = 1;  // 9
        d = 2;  // 10
        do {
            e = 2;  // 11
            do {
                g = d;         // 12
                g *= e;        // 13
                g -= b;        // 14
                if (g == 0) {  // 15
                    f = 0;     // 16
                }
                e += 1;        // 17
                g = e;         // 18
                g -= b;        // 19
            } while (g != 0);  // 20
            d += 1;            // 21
            g = d;             // 22
            g -= b;            // 23
        } while (g != 0);      // 24
        if (f == 0) {          // 25
            h += 1;            // 26
        }
        g = b;         // 27
        g -= c;        // 28
        if (g == 0) {  // 29
            break;
        }
        b += 17;  // 31
    }
}