#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int arr[3001];
    int N;
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        bool flag = true;
        int mark[3001] = {0};
        for (int i = 0; i < N; i++) {
            int diff = abs(arr[i] - arr[i - 1]);
            if (diff < N) {
                ++mark[diff];
            }
        }
        for (int i = 1; i < N; i++) {
            if (!mark[i]) {
                flag = false;
            }
        }
        cout << (flag ? "Jolly\n" : "Not jolly\n");
    }
    return 0;
}