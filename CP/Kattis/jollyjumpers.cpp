#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        int arr[3005]{};
        int pre;
        scanf("%d", &pre);
        for (int i = 1; i < N; i++) {
            int cur;
            scanf("%d", &cur);
            arr[abs(cur - pre)]++;
            pre = cur;
        }
        bool flag = true;
        for (int i = 1; i < N; i++) {
            if (!arr[i]) {
                flag = false;
            }
        }
        if (flag) {
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }
}