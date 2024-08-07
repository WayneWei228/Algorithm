#include <iostream>
#include <cstdio>
#include <algorithm>
const int MAXN = 100000;
using namespace std;

long long score[MAXN + 1];
long long suffix_sum[MAXN + 1];
long long suffix_min[MAXN + 1];
long long best_num, best_den;

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> score[i];
    }

    suffix_sum[N] = score[N];
    suffix_min[N] = score[N];

    for(int i = N - 1; i >= 1; i--) {
        suffix_sum[i] = suffix_sum[i + 1] + score[i];
        suffix_min[i] = min(suffix_min[i + 1], score[i]);
    }
    best_num = 0;
    best_den = 1;
    
    for(int i = 1; i <= N - 2; i++) {
        if((suffix_sum[i + 1] - suffix_min[i + 1]) * best_den > best_num * (N - i - 1)) {
            best_num = suffix_sum[i + 1] - suffix_min[i + 1];
            best_den = N - i - 1;
        }
    }

    for(int i = 1; i <= N - 2; i++){
        if((suffix_sum[i + 1] - suffix_min[i + 1]) * best_den == best_num * (N - i - 1)) {
            cout << i << endl;
        }
    }
    return 0;
}

