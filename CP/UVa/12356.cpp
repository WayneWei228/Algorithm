#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int s, b;
    while (scanf("%d %d", &s, &b) == 2 && s && b) {
        int L1[100005], R1[100005];
        for (int i = 1; i <= s; i++) {
            L1[i] = i - 1;
            R1[i] = i + 1;
        }
        for (int i = 0; i < b; i++) {
            int L, R;
            scanf("%d %d", &L, &R);
            if (L1[L] < 1) {
                printf("*");
            } else {
                printf("%d", L1[L]);
            }
            if (R1[R] > s) {
                printf(" *\n");
            } else {
                printf(" %d\n", R1[R]);
            }
            L1[R1[R]] = L1[L];
            R1[L1[L]] = R1[R];
        }
        printf("-\n");
    }
    return 0;
}