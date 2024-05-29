#include <iostream>
#include <cstdio>
using namespace std;

int N;
bool arr[200005];

int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        arr[temp] = true;
    }
    int size = 2*N;
    int num = 0;
    int cnt = 0;
    for(int i = size; i >= 1; i--) {
        if(!arr[i]) {
            num += 1;
        } 
        if(arr[i] && num != 0) {
            num -= 1;
            cnt += 1;
        }
    }
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


/*

TFFTFT
TTTFFF
FTFTFT

*/
