#include <cstdio>
#include <string>
#include <vector>
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
    int64 e = 1;
    while (e <= c) {
        int64 b = 1;
        while (b <= c) {
            if (e * b == c) {
                a += e;
            }
            b++;
        }
        e++;
    }
    printf("%lld\n", a);
    return 0;
}