#include <cstdio>
using namespace std;

typedef long long int64;

const int64 a = 1;

int main() {
    int64 e = 2 * 2 * 19 * 11 + 6 * 22 + 2;
    if (a == 1) e += (27 * 28 + 29) * 30 * 14 * 32;
    int64 divisorSum = 0, i = 1;
    for (; i * i < e; ++i) {
        if (e % i == 0) divisorSum += i + e / i;
    }
    if (i * i == e) divisorSum += i;
    printf("%lld\n", divisorSum);
    return 0;
}
