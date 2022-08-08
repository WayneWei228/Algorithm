#include <cstdio>
#include <iostream>
using namespace std;

int M, N, K;
int arr[2][10000005];

int main() {
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++) {
        char temp;
        int num;
        cin >> temp >> num;
        if(temp == 'R') {
            arr[0][num]++;
            if(arr[0][num] % 2 == 0) {
                arr[0][num] = 0;
            }
        }
        if(temp == 'C') {
            arr[1][num]++;
            if(arr[1][num] % 2 == 0) {
                arr[1][num] = 0;
            }
        }
    }
    int gold = 0;
    int cnt = 0;
    for(int i = 1; i <= M; i++) {
        if(arr[0][i] != 0) {
            gold += N;
            cnt++;
        }
    }
    for(int i = 1; i <= N; i++) {
        if(arr[1][i] != 0) {
            gold -= cnt;
            gold += (M - cnt);
        }
    }
    cout << gold << endl;
    return 0;
}