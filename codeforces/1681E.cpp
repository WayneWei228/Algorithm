#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const long long INF64 = 1e18;

int main() {
    int n;
    cin >> n;
    /*
    n layers
    n - 1 layers have doors
    */
    vector<vector<pair<int, int>>> d(n - 1, vector<pair<int, int>>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> d[i][j].first >> d[i][j].second;
            --d[i][j].first;
            --d[i][j].second;
        }
    }
    /*
        n layers
        1 + x = n - 1
        x = n - 2;
    */
    int lg = 1;
    while ((1 << lg) < n) lg++;
    vector<vector<vector<vector<long long>>>> dp(
        n - 2, vector<vector<vector<long long>>>(
                   lg, vector<vector<long long>>(
                           2, vector<long long>(2, INF64))));
    // dp[i][0][j][k]
    for (int i = 0; i + 1 < n - 1; i++) {
        for (int k = 0; k < 2; k++) {
            dp[i][0][0][k] =
                abs(d[i][0].first + 1 - d[i + 1][k].first) +
                abs(d[i][0].second - d[i + 1][k].second) + 1;
            dp[i][0][1][k] =
                abs(d[i][1].first + 1 - d[i + 1][k].first) +
                abs(d[i][1].second - d[i + 1][k].second) + 1;
        }
    }

    return 0;
}