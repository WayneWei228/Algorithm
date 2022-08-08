//USACO 2020 January Contest, Silver Problem 1. Berry Picking
/*
 Bessie 和她的妹妹 Elsie 正在 Farmer John 的浆果园里采浆果。Farmer John 的浆果园里有 N 棵浆果树（1≤N≤1000）；树 i 上有 Bi 个浆果（1≤Bi≤1000）。Bessie 有 K 个篮子（1≤K≤1000，K 为偶数）。每个篮子里可以装同一棵树上采下的任意多个浆果，但是不能装来自于不同的树上的浆果，因为它们的口味可能不同。篮子里也可以不装浆果。
 Bessie 想要使得她得到的浆果数量最大。但是，Farmer John 希望 Bessie 与她的妹妹一同分享，所以 Bessie 必须将浆果数量较多的 K/2 个篮子给 Elsie。这表示 Elsie 很有可能最后比 Bessie 得到更多的浆果，这十分不公平，然而姐妹之间往往就是这样。

 帮助 Bessie 求出她最多可以得到的浆果数量。

 测试点性质：
 */
/*
 Small K:

 After sorting the trees in decreasing order of Bi, we don't need to consider trees outside of the first K. Furthermore, if we decide to select b>0 baskets from tree i, then each basket should have either ⌊Bi/b⌋ or ⌊Bi/b⌋+1 berries. Using these observations, we can do some sort of backtracking.

 Full Solution:
* b - the minimum number of berries in one of the buckets that Elsie receives
 
 * we assume that all of Elsie's buckets contain exactly b berries
 
 Let b the minimum number of berries in one of the buckets that Elsie receives. Without loss of generality, we can assume that all of Elsie's buckets contain exactly b berries. Now our goal is to maximize the number of berries placed into K buckets of size at most b such that at least K/2 buckets have exactly b berries inside.

 Consider a single tree's allotment into the buckets in an optimal solution. There's no point having multiple buckets with less than b berries from this tree. So all buckets will have exactly b berries aside from at most one.

 Thus, it's clearly optimal to repeatedly fill buckets of size exactly b until we run out of buckets or all trees have less than b berries remaining. If we still have buckets to fill, sort the remaining trees by Bi(mod b) and iterate from the largest to the smallest value.
 */
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int N, K;
// int A[100000];
// int mod;


// bool cmp (int a, int b) {
//     return (a % mod) > (b % mod);
// }
// int main() {
//     freopen("berries.in", "r", stdin);
// 	   freopen("berries.out", "w", stdout);
//     cin >> N >> K;
//     int M = 0;
//     for(int i = 0; i< N; i++) {
//         cin >> A[i];
//         M = max(M, A[i]);
//     }
//     int best = 0;
//     for(int b = 1 ; b <= M; b++) {
//         int full = 0;
//         for(int i = 0; i < N; i++) {
//             full += A[i]/b;
//         }
//         if(full < K/2) 
//             break;
//         else if(full >= K) {
//             best = max(best, b * (K / 2));
//         } else
//         {
//             mod = b;
//             sort(A, A + N, cmp);
//             int cur = b * (full - K / 2);
//             for(int i = 0; i < N && i + full < K; i++) {
//                 cur += A[i] % b;
//             }
//             best = max(best, cur);
//         }
//     }
//     cout << best << '\n';
//     fclose(stdin);
//     fclose(stdout);
//     return 0;
// }


// redo
#include <bits/stdc++.h>
using namespace std;

int N, K, M;
int arr[10000];
int mod;
bool cmp(int a, int b) {
    return (a % mod) < (b % mod);
}
int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        M = max(arr[i], M);
    }
    int best;
    for(int b = 1; b <= M; b++) {
        int full;
        for(int i = 0; i < N; i++) {
            full += arr[i] / b;
        }
        if(full < K / 2) {
            break;
        }
        if(full >= K) {
            best = max(best, b * K / 2);
            continue;
        }
        mod = b;
        int cur = b * (full - K / 2);
        sort(arr, arr + N, cmp);
        for(int i = 0; i < N && i + full < K; i++) {
            cur += arr[i] % b;
        }
        best = max(best, cur);
    }
}







