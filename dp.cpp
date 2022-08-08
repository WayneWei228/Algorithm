#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int N = 3;
    int W = 5;
    int wt[3] = {3, 1, 2};
    int value[3] = {1, 4, 2};
    int dp[N + 1][W + 1];
    
    for(int i = 0; i <= W; i++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= N; i++) {
        for(int w = 0; w <= W; w++) {
            if(w - wt[i - 1] < 0) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + value[i - 1]);
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int w = 0; w <= W; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }
}