#include <iostream>
#define ll long long
using namespace std;

/*
4
3 3 1 1
1 1 3 1
3 3 1 1
1 1 3 3
*/

ll grid[1000][1000];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        } 
    }
    ll horizontalAnswer = 0;
    for(int i = 0; i < n; i++) {
        ll sum[2];
        sum[0] = 0;
        sum[1] = 0;
        for(int j = 0; j < n; j++) {
            sum[j % 2] += grid[i][j];
        }
        horizontalAnswer += max(sum[0], sum[1]);
    }

    ll verticalAnswer = 0;
    for(int i = 0; i < n; i++) {
        ll sum[2];
        sum[0] = 0;
        sum[1] = 0;
        for(int j = 0; j < n; j++) {
            sum[j % 2] += grid[j][i];
        }
        verticalAnswer += max(sum[0], sum[1]);
    }
    cout << max(horizontalAnswer,verticalAnswer) << endl;
    return 0;
}