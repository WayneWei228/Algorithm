#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct Solution {
    long long num;
    long long ans = 0;
    void Solve() {
        cin >> num;
        ans += (1 + num) * num / 2;
        int lg = (int)log2(num);
        long long mius = pow(2, lg + 1) - 1;
        ans -= mius;
        ans -= mius;
        cout << ans << endl;
    }
};

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {   
        Solution().Solve();
    }
    return 0;
} 
