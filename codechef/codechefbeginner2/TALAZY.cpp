#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

/*
2
9 1 2
123456 123456 123456
*/

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        long long int N, B, M;
        cin >> N >> B >> M;
        long long int ans = 0;
        long long int done,left;
        while (N > 0) {
            left = N / 2;
            done = N - left;
            ans += (done * M + B);
            M *= 2;
            N -= done;
        }
        ans -= B;
        cout << ans << '\n';
        /*
        long long ans = 0;
        while(true) {
            long long problems = (N + 1) / 2;
            ans += problems * M;
            N -= problems; 
            if(N == 0) break;
            ans += B;
            M += M;
        }
        */
    }
    return 0;
}