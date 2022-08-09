#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int N, K ,B;
    cin >> N >> K >> B;
    vector<int> arr;
    arr.resize(N);
    for(int i = 0; i < B; i++) {
        int temp;
        cin >> temp;
        arr[temp - 1] = 1;
    }
    for(int i = 0; i < N; i++) {
        arr[i] += arr[i-1];
    }
    int ans = 100005;
    for(int i = K - 1; i < N; i++) {
        ans = min(ans, arr[i] - arr[i - K]);
    }
    cout << ans << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}