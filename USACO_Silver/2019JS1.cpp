#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int S[100005];

int main() {
    freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        S[a] += 1;
        S[b] += 1;
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans = max(ans, S[i]);
    }
    ans += 1;
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}