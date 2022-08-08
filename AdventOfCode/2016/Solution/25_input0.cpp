#include <cstdio>
using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d", &a);
    d = a;
    c = 7;
    do {
        b = 362;
        do {
            ++d;
            --b;
        } while (b);
        --c;
    } while (c);
    a = d;
    for (;;) {
        b = a;
        a = 0;
        for (;;) {
            c = 2;
            do {
                if (!b) goto break1;
                --b;
                --c;
            } while (c);
            ++a;
        }
break1:
        b = 2;
        for (;;) {
            if (c) {
                --b;
                --c;
            } else break;
        }
        printf("%d\n", b);
        if (!a) a = d;
    }
}
