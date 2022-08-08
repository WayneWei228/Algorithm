#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;

int main() {
    int64 a, b, c, d, e, f;
    goto Label1;
Label4:
    e = 1;
Label9:
    b = 1;
Label7: // Label7 循环
    d = e * b;
    d = d == c;
    if (d == 1) {
        goto Label3;
    }
    goto Label5;
Label3:
    a += e;
Label5:
    b += 1;
    d = b > c;
    if (d == 1) {
        goto Label6; // 跳出循环
    }
    goto Label7;
Label6:
    e += 1;
    d = e > c;
    if (d == 1) {
        goto Label0;
    }
    goto Label9;
Label0:
    printf("%lld\n", a);
    return 0;
Label1:
    c += 2;
    c *= c;
    c = c * 19;
    c = c * 11;
    d += 6;
    d *= 22;
    d += 9;
    c += d;
    // assume a <= 1;
    if (a == 1) {
        goto Label2;
    }
    goto Label4;
Label2:
    d = 27;
    d *= 28;
    d += 29;
    d *= 30;
    d *= 14;
    d *= 32;
    c += d;
    a = 0;
    goto Label4;
}
