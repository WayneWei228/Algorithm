#include <cstdio>
using namespace std;

int main() {
    int N;
    int arr[1005][2];
    int ans[1005] = {0};
    while (scanf("%d", &N) == 1 && N) {
        int rank[10005] = {}, err = 0;
        int x, v;
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &x, &v);
            if (i + v < 0) err = 1;
            if (i + v >= N) err = 1;
            if (!err && rank[i + v]) err = 1;
            if (err) continue;
            rank[i + v] = x;
        }
        if (err) {
            printf("-1\n");
            continue;
        }
        printf("%d", rank[0]);
        for (int i = 1; i < N; i++) {
            printf(" %d", rank[i]);
        }
        printf("\n");
    }
    return 0;
}