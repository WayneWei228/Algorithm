#include <cstdio>
using namespace std;

typedef long long int64;

int main() {
    int64 a = 1;
    int64 c = 2 * 2 * 19 * 11 + 6 * 22 + 9;
    int64 d = 6 * 22 + 9;
    if (a == 1) {
        c += (27 * 28 + 29) * 30 * 14 * 32;
    }
    a = 0;
    // 所有质因数之和
    for (int64 i = 1; i <= c; i++) {
        if (c % i == 0) a += i + (c / i);
    }
    a /= 2;
    // a = 0;
    // int64 i = 1;
    // for (; i * i < c; i++) {
    //     if (c % i == 0) a += i + c / i;
    // }
    // if (i * i == c) a += i;
    printf("%lld\n", a);
}