#include <cstdio>
using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d", &a);
    d = a + 2534;
    a = d;
    for (;;) {
        printf("%d\n", a & 1);
        a >>= 1;
        if (!a) a = d;
    }
}
