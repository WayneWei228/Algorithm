#include <cstdio>
using namespace std;

typedef long long int64;

int main() {
    int64 a = 0, c = 0, d = 0, e = 0, f = 0;
    goto label1;
label9:
    d = 1;
label7:
    f = 1;
label5:
    c = d * f;
    c = c == e;
    if (c == 1) {
        goto label2;
    }  // assume c <= 1
    goto label3;
label2:
    a = d + a;
label3:
    f = f + 1;
    c = f > e;
    if (c == 1) {
        goto label4;
    }  // assume c <= 1
    goto label5;
label4:
    d = d + 1;
    c = d > e;
    if (c == 1) {
        goto label6;
    }  // assume c <= 1
    goto label7;
label6:
    printf("%lld\n", a);
    return 0;
label1:
    e = e + 2;
    e = e * e;
    e = 19 * e;
    e = e * 11;
    c = c + 6;
    c = c * 22;
    c = c + 2;
    e = e + c;
    if (a == 1) {
        goto label8;
    }  // assume a <= 1
    goto label9;
label8:
    c = 27;
    c = c * 28;
    c = 29 + c;
    c = 30 * c;
    c = c * 14;
    c = c * 32;
    e = e + c;
    a = 0;
    goto label9;
}
