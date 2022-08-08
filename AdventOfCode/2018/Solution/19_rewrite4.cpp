#include <cstdio>
using namespace std;

typedef long long int64;

const int64 a = 0;

int main() {
    int64 e = 2 * 2 * 19 * 11 + 6 * 22 + 2;
    if (a == 1) e += (27 * 28 + 29) * 30 * 14 * 32;
    int64 answer = 0;
    int64 d = 1;
    while (d <= e) {
        int64 f = 1;
        while (f <= e) {
            if (d * f == e) answer += d;
            ++f;
        }
        ++d;
    }
    printf("%lld\n", answer);
    return 0;
}
